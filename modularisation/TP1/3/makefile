CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

all : secretAgent

# Secret Agent
secretAgent : secretAgent.o crypt.o utils_v1.o
	cc $(CFLAGS) -o secretAgent secretAgent.o crypt.o utils_v1.o

secretAgent.o : secretAgent.c crypt.h utils_v1.h
	cc $(CFLAGS) -c secretAgent.c

# Crypt
crypt.o : crypt.c crypt.h
	cc $(CFLAGS) -c crypt.c

# Utils
utils_v1.o : utils_v1.c utils_v1.h
	cc $(CFLAGS) -c utils_v1.c

clean :
	rm *.o
	rm secretAgent
