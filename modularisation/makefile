CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

schtroumph : encrypt decrypt

encrypt : encrypt.o crypt.o utils_v1.o
	cc $(CFLAGS) -o encrypt encrypt.o crypt.o utils_v1.o

decrypt : decrypt.o crypt.o utils_v1.o
	cc $(CFLAGS) -o decrypt decrypt.o crypt.o utils_v1.o

encrypt.o : encrypt.c
	cc $(CFLAGS) -c encrypt.c

decrypt.o : decrypt.c
	cc $(CFLAGS) -c decrypt.c

utils_v1.o : utils_v1.c
	cc $(CFLAGS) -c utils_v1.c

crypt.o : crypt.c
	cc $(CFLAGS) -c crypt.c

clean :
	rm *.o
	rm encrypt
	rm decrypt