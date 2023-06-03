CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

all : encrypt decrypt

# Encrypt
encrypt : encrypt.o crypt.o utils_v1.o
	cc $(CFLAGS) -o encrypt encrypt.o crypt.o utils_v1.o

encrypt.o : encrypt.c crypt.h utils_v1.h
	cc $(CFLAGS) -c encrypt.c

# Decrypt
decrypt : decrypt.o crypt.o utils_v1.o
	cc $(CFLAGS) -o decrypt decrypt.o crypt.o utils_v1.o

decrypt.o : decrypt.c crypt.h utils_v1.h
	cc $(CFLAGS) -c decrypt.c

# Crypt
crypt.o : crypt.c crypt.h
	cc $(CFLAGS) -c crypt.c

# Utils
utils_v1.o : utils_v1.c utils_v1.h
	cc $(CFLAGS) -c utils_v1.c

clean :
	rm *.o
	rm encrypt
	rm decrypt
