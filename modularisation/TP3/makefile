CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall

# Biblio
schtroumph : main

main : main.o
	cc $(CFLAGS) -o main main.o

main.o : main.c
	cc $(CFLAGS) -c main.c

# Clean
clean :
	rm *.o
	rm main