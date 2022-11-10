/********************************* ex2.5.c **********************************/

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

    // Generation de la matrice de maniere aleatoire
    char matrice[MAXDIM][MAXDIM];
    for (int i=0; i<nl; i++) {
        for (int j=0; j<nc; j++) {
            matrice[i][j] = 'A' + (int) (rand()/(RAND_MAX+1.0)*26);
        }
    }

    // Affichage de la matrice
    printf("\n");
    for (int i=0; i<nl; i++) {
        for (int j=0; j<nc; j++)
            printf("%c  ", matrice[i][j]);
        printf("\n");
    }
    printf("\n");

    // Calcul du nombre d'occurences par ligne
    int count[MAXDIM][26] = {{0}};
    for (int i=0; i<nl; i++) {
        for (int j=0; j<nc; j++)
            count[i][matrice[i][j]-'A']++;
    }

    // Affichage du nombre d'occurences par ligne
    printf("         ");
    for (char c='A'; c<='Z'; c++)
        printf(" %c",c);
    printf("\n\n");
    for (int i=0; i<nl; i++) {
        printf("Ligne %d: ",i+1);
        for (int j=0; j<26; j++)
            printf(" %d", count[i][j]);
        printf("\n");
    }
    printf("\n");

    exit(0);
}
