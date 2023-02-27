CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall

# Main
schtroumph : main

main : main.o pile.o
	cc $(CFLAGS) -o main main.o pile.o

main.o : main.c
	cc $(CFLAGS) -c main.c

pile.o : pile.c pile.h
	cc $(CFLAGS) -c pile.c

# Clean
clean :
	rm *.o
	rm main