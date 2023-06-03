#include <stdlib.h>
#include <stdio.h>

#include "biblio.h"

int main (int argc, char **argv) {
   struct Livre *maBib= NULL;
   int nbreLivre = 0;
   int tailleP = 0;
   struct Livre unLivre;

   while (lireLivre(&unLivre)) {
      if (!ajouterLivre(&maBib, unLivre, &nbreLivre, &tailleP))
         perror("Erreur ajout de livre");
		
      getchar();
   }

   afficherBib(maBib, nbreLivre);
}