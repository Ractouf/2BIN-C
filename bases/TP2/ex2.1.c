/********************************* ex2.1.c **********************************/

#include <stdlib.h>
#include <stdio.h>

#define NBMAX 50   // nombre maximal d'etudiants

int main ()
{
    int val;
    float notes [NBMAX];
    int cpt=0;
    float som = 0;

    // Lecture des notes des etudiants
    printf("Entrez les notes des etudiants, Ctrl-D pour terminer:\n");
    while ((cpt < NBMAX) && (scanf("%d",&val) != EOF)) {    // scanf() renvoie EOF pour tous les appels 
                                                            // qui suivent un Ctrl-D ==> plus de lecture 
                                                            // possible sur stdin
            notes[cpt] = val;
            som += val;
            cpt++;
    }

    // Calcul de la moyenne
    float moy = som/cpt;
    printf("Moyenne = %.2f\n", moy);

    // Calcul des ecarts a la moyenne
    printf("Ecarts des etudiants par rapport a la moyenne:\n");
    float ecart;
    som = 0;
    for (int i=0; i<cpt; i++) {
            ecart = notes[i]-moy;
            printf("   Etudiant %d: %.2f\n", i+1, ecart);
            som += ecart * ecart;
    }

    // Calcul de la variance
    float var = som/cpt;
    printf("Variance = %.2f\n", var);

    exit(0);
}
