CC=gcc
# Make sure C_INCLUDE_PATH, LD_LIBRARY_PATH and LIBRARY_PATH contain dirs
# where FLINT and Arb are installed (~/local_<lib_name>)
LIBS=-larb -lflint -lmpfr -lgmp -lpthread
# Directory to keep object files:
ODIR=obj

_OBJ = poly_roots.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Rule to generate object files:
$(ODIR)/%.o: %.c
	$(CC) -c -o $@ $<

poly_roots: $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

.PHONY: clean # Keep make from doing smth with file named clean.

clean:
	rm -f $(ODIR)/*.o poly_roots
