CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall

schtroumph : encrypt decrypt

crypt.o: encrypt.o decrypt.o
	cc $(CFLAGS) -o crypt.o encrypt.o decrypt.o

encrypt : encrypt.o 
	cc $(CFLAGS) -o encrypt encrypt.o

decrypt : decrypt.o 
	cc $(CFLAGS) -o decrypt decrypt.o

encrypt.o : utils_v1.o
	cc $(CFLAGS) -o encrypt.o utils_v1.o

decrypt.o : utils_v1.o
	cc $(CFLAGS) -o decrypt.o utils_v1.o

clean :
	rm *.o
	rm npi