CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

# Biblio
schtroumph : testBiblio.o biblio.o utils_v1.o
	gcc $(CFLAGS) -o testBiblio testBiblio.o biblio.o utils_v1.o

testBiblio.o : biblio.h testBiblio.c
	gcc $(CFLAGS) -c testBiblio.c

biblio.o : biblio.c biblio.h utils_v1.h
	cc $(CFLAGS) -c biblio.c

# Utils
utils_v1.o : utils_v1.c utils_v1.h
	cc $(CFLAGS) -c utils_v1.c

# Clean
clean :
	rm *.o
	rm testBiblio