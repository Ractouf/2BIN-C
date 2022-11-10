/********************************* ex2.3.c **********************************/

#include <stdlib.h>
#include <stdio.h>

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

    // Generation de la matrice colonne par colonne
    char matrice2[MAXDIM][MAXDIM];
    cpt = 0;
    for (int i=0; i<nc; i++) {
        for (int j=0; j<nl; j++) {
            matrice2[j][i] = 'A' + cpt;
            cpt = (cpt+1) % 26;
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
