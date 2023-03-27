CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

# Schtroumph
schtroumph : maev.o utils_v2.o
	gcc $(CFLAGS) -o schtroumph maev.o utils_v2.o

maev.o : maev.c utils_v2.o 
	gcc $(CFLAGS) -c maev.c

# Utils
utils_v2.o : utils_v2.c utils_v2.h
	cc $(CFLAGS) -c utils_v2.c

# Clean
clean :
	rm *.o
	rm schtroumph