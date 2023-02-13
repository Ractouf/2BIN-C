CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

# Biblio
schtroumph : biblio

biblio : biblio.o utils_v1.o
	cc $(CFLAGS) -o biblio biblio.o utils_v1.o

biblio.o : biblio.c
	cc $(CFLAGS) -c biblio.c

# Utils
utils_v1.o : utils_v1.c
	cc $(CFLAGS) -c utils_v1.c

# Clean
clean :
	rm *.o
	rm biblio