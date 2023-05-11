CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

all: zombie controller labo

# Zombie
zombie : zombie.o connection_service.o utils_v2.o
	gcc $(CFLAGS) -o zombie zombie.o connection_service.o utils_v2.o

zombie.o : zombie.c connection_service.h utils_v2.h
	gcc $(CFLAGS) -c zombie.c

# Controller
controller : controller.o connection_service.o utils_v2.o
	gcc $(CFLAGS) -o controller controller.o connection_service.o utils_v2.o

controller.o : controller.c connection_service.h utils_v2.h
	gcc $(CFLAGS) -c controller.c

# Labo
labo : labo.o connection_service.o utils_v2.o
	gcc $(CFLAGS) -o labo labo.o connection_service.o utils_v2.o

labo.o : labo.c connection_service.h utils_v2.h
	gcc $(CFLAGS) -c labo.c

# Connection service
connection_service.o : connection_service.c connection_service.h utils_v2.h
	cc $(CFLAGS) -c connection_service.c

# Utils
utils_v2.o : utils_v2.c connection_service.h utils_v2.h
	cc $(CFLAGS) -c utils_v2.c

# Clean
clean :
	rm *.o
	rm zombie
	rm controller
	rm labo
	