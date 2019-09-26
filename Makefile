CC=gcc
CFLAGS=-I. \
	-fCPIC
DEPS = to_bits.h
OBJ = main.o to_bits.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

BitMan: $(OBJ)
	$(CC) -o $@ main.o to_bits.o

clean:
	rm -f *.o *~ BitMan
