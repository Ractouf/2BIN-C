CFLAGS=-std=c11 -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE

# Biblio
schtroumph : createInscriptionRequests.o
	gcc $(CFLAGS) -o schtroumph createInscriptionRequests.o

createInscriptionRequests.o : createInscriptionRequests.c inscriptionRequest.h 
	gcc $(CFLAGS) -c createInscriptionRequests.c

# Clean
clean :
	rm *.o
	rm schtroumph