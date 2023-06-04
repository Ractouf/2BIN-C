CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

all: b

b: b.o utils_v2.o 
	cc $(CFLAGS) -o b b.o utils_v2.o

b.o: b.c utils_v2.h
	cc $(CFLAGS) -c b.c

# Utils
utils_v2.o: utils_v2.c utils_v2.h
	cc $(CFLAGS) -c utils_v2.c

# Clean
clean:
	rm *.o
	rm b