CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

schtroumph : encrypt decrypt encryptPolybe decryptPolybe

# Rot13
encrypt : encrypt.o crypt.o utils_v1.o
	cc $(CFLAGS) -o encrypt encrypt.o crypt.o utils_v1.o

decrypt : decrypt.o crypt.o utils_v1.o
	cc $(CFLAGS) -o decrypt decrypt.o crypt.o utils_v1.o

encrypt.o : encrypt.c
	cc $(CFLAGS) -c encrypt.c

decrypt.o : decrypt.c
	cc $(CFLAGS) -c decrypt.c

crypt.o : crypt.c
	cc $(CFLAGS) -c crypt.c

# Polybe
encryptPolybe : encryptPolybe.o cryptPolybe.o utils_v1.o
	cc $(CFLAGS) -o encryptPolybe encryptPolybe.o cryptPolybe.o utils_v1.o

decryptPolybe : decryptPolybe.o cryptPolybe.o utils_v1.o
	cc $(CFLAGS) -o decryptPolybe decryptPolybe.o cryptPolybe.o utils_v1.o

encryptPolybe.o : encryptPolybe.c
	cc $(CFLAGS) -c encryptPolybe.c

decryptPolybe.o : decryptPolybe.c
	cc $(CFLAGS) -c decryptPolybe.c

cryptPolybe.o : cryptPolybe.c
	cc $(CFLAGS) -c cryptPolybe.c

# Utils
utils_v1.o : utils_v1.c
	cc $(CFLAGS) -c utils_v1.c


clean :
	rm *.o
	rm encrypt
	rm decrypt
	rm encryptPolybe
	rm decryptPolybe