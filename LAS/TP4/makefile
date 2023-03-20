CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

# Schtroumph
schtroumph : exemple.o utils_v2.o
	gcc $(CFLAGS) -o schtroumph exemple.o utils_v2.o

exemple.o : exemple.c utils_v2.o 
	gcc $(CFLAGS) -c exemple.c

# Utils
utils_v2.o : utils_v2.c utils_v2.h
	cc $(CFLAGS) -c utils_v2.c

# Clean
clean :
	rm *.o
	rm schtroumph