CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

all: damien

damien: damien.o utils_v2.o
	cc $(CFLAGS) -o damien damien.o utils_v2.o

damien.o: damien.c
	cc $(CFLAGS) -c damien.c

utils_v2.o: utils_v2.c utils_v2.h
	cc $(CFLAGS) -c utils_v2.c

clean:
	rm damien
	rm *.o
	