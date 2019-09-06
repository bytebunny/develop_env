CC=gcc
LIBS=-larb -lflint -lmpfr -lgmp -lpthread
# Directory to keep object files:
ODIR=obj

_OBJ = test.o stack_allocation.o heap_allocation.o memory_fragmentation.o \
	avoid_memory_fragmentation.o write_check_matrix.o

OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Rule to generate object files:
$(ODIR)/%.o: %.c
	$(CC) -c -o $@ $<

all: test stack_allocation heap_allocation memory_fragmentation \
	avoid_memory_fragmentation write_check_matrix
.PHONY: all

write_check_matrix: $(ODIR)/write_check_matrix.o
	$(CC) -o $@ $^ -O1

stack_allocation: $(ODIR)/stack_allocation.o
	$(CC) -o $@ $^ -O1

heap_allocation: $(ODIR)/heap_allocation.o
	$(CC) -o $@ $^ -O1

memory_fragmentation: $(ODIR)/memory_fragmentation.o
	$(CC) -o $@ $^ -O1

avoid_memory_fragmentation: $(ODIR)/avoid_memory_fragmentation.o
	$(CC) -o $@ $^ -O1

test: $(ODIR)/test.o
	$(CC) -o $@ $^ $(LIBS)

.PHONY: clean # Avoid conflict with a file of the same name
clean:
	rm -f $(ODIR)/*.o test stack_allocation heap_allocation \
	memory_fragmentation avoid_memory_fragmentation write_check_matrix
