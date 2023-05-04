CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

all: zombie controller

# Zombie
zombie : zombie.o utils_v2.o
	gcc $(CFLAGS) -o zombie zombie.o utils_v2.o

zombie.o : zombie.c utils_v2.h 
	gcc $(CFLAGS) -c zombie.c

# Controller
controller : controller.o utils_v2.o
	gcc $(CFLAGS) -o controller controller.o utils_v2.o

controller.o : controller.c utils_v2.h 
	gcc $(CFLAGS) -c controller.c

# Utils
utils_v2.o : utils_v2.c utils_v2.h
	cc $(CFLAGS) -c utils_v2.c

# Clean
clean :
	rm *.o
	rm zombie
	rm controller