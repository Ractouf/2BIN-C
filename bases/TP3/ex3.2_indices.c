#include <stdio.h>
#include <stdlib.h>

// SOLUTION PAR INDICES
// Cette solution suppose que l'utilisateur ne fera pas d'erreur 
// en introduisant les données

// Liens vers vidéo explicative: https://youtu.be/3se3fusg7zc

int main (int argc, char **argv)
{
   int nData, nPos, nNeg;
   int *inputs, *positives, *negatives;

   printf("Entrez le nombre de donnees (0 pour terminer): ");
   scanf("%d", &nData);

   while (nData>0) {
      inputs = malloc(nData*sizeof(int));
      if (inputs == NULL) {
         perror("Out of memory\n");
         exit(EXIT_FAILURE);
      }

      // Read inputs and counts neg and pos
      printf("Entrez les donnees:\n");
      nPos = nNeg = 0;      
      for (int i=0; i<nData; i++) {
         scanf("%d", inputs+i);
         if (inputs[i]>=0)
            nPos++;
         else
            nNeg++;
      }

      positives = malloc(nPos*sizeof(int));
      if (positives == NULL) {
         perror("Out of memory\n");
         exit(EXIT_FAILURE);
      }
      negatives = malloc(nNeg*sizeof(int));
      if (negatives == NULL) {
         perror("Out of memory\n");
         exit(EXIT_FAILURE);
      }

      // Fill pos and neg arrays
      nPos = nNeg = 0;
      for (int i=0; i<nData; i++) {
         if (inputs[i]>=0) {
            positives[nPos] = inputs[i];
            nPos++;
         }
         else {
            negatives[nNeg] = inputs[i];
            nNeg++;
         }
      }

      // Print arrays
      printf("Resultat : \n");
      for (int i=0; i<nPos; i++)
         printf("%d ", positives[i]);
      printf("\n");

      for (int i=0; i<nNeg; i++)
         printf("%d ", negatives[i]);
      printf("\n");

      // Free dynamic memory
      free(inputs);
      free(negatives);
      free(positives);

      printf("Entrez le nombre de donnees (0 pour terminer): ");
      scanf("%d", &nData);
   }
   
}
