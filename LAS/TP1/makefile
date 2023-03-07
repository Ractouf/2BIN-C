CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

# Biblio
schtroumph : lireEcrire.o utils_v2.o
	gcc $(CFLAGS) -o schtroumph lireEcrire.o utils_v2.o

lireEcrire.o : lireEcrire.c utils_v2.o
	gcc $(CFLAGS) -c lireEcrire.c

# Utils
utils_v2.o : utils_v2.c utils_v2.h
	cc $(CFLAGS) -c utils_v2.c

# Clean
clean :
	rm *.o
	rm schtroumph