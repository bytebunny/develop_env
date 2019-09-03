CC=gcc
LIBS=-larb -lflint -lmpfr -lgmp -lpthread
# Directory to keep object files:
ODIR=obj

_OBJ = test.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Rule to generate object files:
$(ODIR)/%.o: %.c
	$(CC) -c -o $@ $<

test: $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

.PHONY: clean # Keep make from doing smth with file named clean.

clean:
	rm -f $(ODIR)/*.o
