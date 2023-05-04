CFLAGS=-g -std=c11 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

all: zombie controller labo

# Zombie
zombie : zombie.o utils_v2.o
	gcc $(CFLAGS) -o zombie zombie.o utils_v2.o

zombie.o : zombie.c zombie.h utils_v2.h 
	gcc $(CFLAGS) -c zombie.c

# Controller
controller : controller.o utils_v2.o
	gcc $(CFLAGS) -o controller controller.o utils_v2.o

controller.o : controller.c controller.h utils_v2.h 
	gcc $(CFLAGS) -c controller.c

# Labo
labo : labo.o utils_v2.o
	gcc $(CFLAGS) -o labo labo.o utils_v2.o

labo.o : labo.c labo.h utils_v2.h 
	gcc $(CFLAGS) -c labo.c

# Utils
utils_v2.o : utils_v2.c utils_v2.h
	cc $(CFLAGS) -c utils_v2.c

# Clean
clean :
	rm *.o
	rm zombie
	rm controller
	rm labo
	