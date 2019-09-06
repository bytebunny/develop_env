CC=gcc
LIBS=-larb -lflint -lmpfr -lgmp -lpthread
# Directory to keep object files:
ODIR=obj

_OBJ = test.o stack_allocation.o heap_allocation
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Rule to generate object files:
$(ODIR)/%.o: %.c
	$(CC) -c -o $@ $<

all: test stack_allocation heap_allocation
.PHONY: all

stack_allocation: $(ODIR)/stack_allocation.o
	$(CC) -o $@ $^ -O1

heap_allocation: $(ODIR)/heap_allocation.o
	$(CC) -o $@ $^ -O1

test: $(ODIR)/test.o
	$(CC) -o $@ $^ $(LIBS)

.PHONY: clean # Avoid conflict with a file of the same name
clean:
	rm -f $(ODIR)/*.o test stack_allocation heap_allocation
