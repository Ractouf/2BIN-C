CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

all : encryptPolybe decryptPolybe

# Encrypt
encryptPolybe : encryptPolybe.o crypt.o utils_v1.o
	cc $(CFLAGS) -o encryptPolybe encryptPolybe.o crypt.o utils_v1.o

encryptPolybe.o : encryptPolybe.c crypt.h utils_v1.h
	cc $(CFLAGS) -c encryptPolybe.c

# Decrypt
decryptPolybe : decryptPolybe.o crypt.o utils_v1.o
	cc $(CFLAGS) -o decryptPolybe decryptPolybe.o crypt.o utils_v1.o

decryptPolybe.o : decryptPolybe.c crypt.h utils_v1.h
	cc $(CFLAGS) -c decryptPolybe.c

# Crypt
crypt.o : crypt.c crypt.h
	cc $(CFLAGS) -c crypt.c

# Utils
utils_v1.o : utils_v1.c utils_v1.h
	cc $(CFLAGS) -c utils_v1.c

clean :
	rm *.o
	rm encryptPolybe
	rm decryptPolybe
