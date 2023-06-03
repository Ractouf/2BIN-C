CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

all: biblio

biblio: biblio.o utils_v1.o
	cc $(CFLAGS) -o biblio biblio.o utils_v1.o

biblio.o: biblio.c biblio.h utils_v1.h
	cc $(CFLAGS) -c biblio.c

utils_v1.o: utils_v1.c utils_v1.h
	cc $(CFLAGS) -c utils_v1.c

clean:
	rm biblio
	rm *.o