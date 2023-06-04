CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

all: antoin

antoin: antoin.o utils_v2.o
	cc $(CFLAGS) -o antoin antoin.o utils_v2.o

antoin.o: antoin.c
	cc $(CFLAGS) -c antoin.c

utils_v2.o: utils_v2.c utils_v2.h
	cc $(CFLAGS) -c utils_v2.c

clean:
	rm antoin
	rm *.o