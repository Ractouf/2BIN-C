/********************************* ex2.4.c **********************************/

#include <stdio.h>
#include <stdlib.h>

#define MAXDIM 9

int main () 
{
    // Lecture des dimensions de la matrice
    printf("Entrez le nombre de lignes de la matrice:\n");
    int nl;
    scanf("%d",&nl);
    printf("Entrez le nombre de colonnes de la matrice:\n");
    int nc;    
    scanf("%d",&nc);

    // Generation de la matrice ligne par ligne
    char matrice1[MAXDIM][MAXDIM];
    int cpt = 0;
    for (int i=0; i<nl; i++) {
        for (int j=0; j<nc; j++) {
            matrice1[i][j] = 'A' + cpt;
            cpt = (cpt+1) % 26;
        }
    }

    // Affichage de la matrice
    printf("\n");
    for (int i=0; i<nl; i++) {
        for (int j=0; j<nc; j++)
            printf("%c  ", matrice1[i][j]);
        printf("\n");
    }
    printf("\n");

    // Generation de la matrice de maniere aleatoire
    char matrice2[MAXDIM][MAXDIM];
    for (int i=0; i<nl; i++) {
        for (int j=0; j<nc; j++) {
            matrice2[i][j] = 'A' + (int) (rand()/(RAND_MAX+1.0)*26);
        }
    }

    // Affichage de la matrice
    printf("\n");
    for (int i=0; i<nl; i++) {
        for (int j=0; j<nc; j++)
            printf("%c  ", matrice2[i][j]);
        printf("\n");
    }
    printf("\n");

    // Affichage des valeurs identiques
    for (int i=0; i<nl; i++) {
        for (int j=0; j<nc; j++)
            if (matrice1[i][j] == matrice2[i][j])
                printf("%c en ligne %d et colonne %d\n", matrice2[i][j], i, j);
    }
    printf("\n");

    exit(0);
}

/*

BONUS:

    void srand(unsigned int seed);

srand seeds the random number generator used by the function rand. Seeding srand with
the same seed will cause rand to return the same sequence of pseudo-random numbers.
If srand is not called, rand acts as if srand(1) has been called.

Solution 1: Initialisation de la random seed avec le temps courant exprimé en secondes
--------------------------------------------------------------------------------------

   srand((unsigned) time(NULL));    // time() défini dans <time.h>

   // Intializes random number generator with current time
   // (srand should only be called once before rand executions)
   // The C library function time_t time(time_t *seconds) returns the time since
   // the Epoch (00:00:00 UTC, January 1, 1970), measured in seconds.

   --> Limite: génère la même suite pseudo-aléatoire si le programme est exécuté 
               deux fois durant la même seconde

               
Solution 2: Initialisation de la random seed avec le temps courant exprimé en microsecondes
-------------------------------------------------------------------------------------------

   struct timeval currentTime;
   gettimeofday(&currentTime, NULL);    // gettimeofday() défini dans <sys/time.h>
   long seed = currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
   srand(seed);

   // gettimeofday() gives the number of seconds and microseconds since the Epoch.

   --> Limite: génère la même suite pseudo-aléatoire si le programme est exécuté 
               deux fois durant la même micro-seconde (ce qui est moins probable 
               que la même seconde)

               
Solution 3: Utilisation du random device de Linux: /dev/urandom
----------------------------------------------------------------

   Explications: http://man7.org/linux/man-pages/man4/random.4.html
   
   Exemple: https://www.guyrutenberg.com/2007/09/03/seeding-srand/
   
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	#include <unistd.h>
	#include <stdio.h>
	#include <stdlib.h>

	#define SSIZE 8

	typedef unsigned int uint;

	uint* genrs () {
		int fd = open("/dev/urandom", O_RDWR);
		uint* seed = (uint*)malloc(sizeof(seed[0]) * SSIZE);
		read(fd, seed, SSIZE);
		return seed;
	}

	// Test
	int main (int argc, char** argv) {
		int LIM = 5;
		for(int i=0; i<LIM; ++i) {
			srand(*genrs());
			printf(“Random number: %d\n”, rand());
		}
		return 0;
	}
    
*/
