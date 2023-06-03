#include "biblio.h"
#include "utils_v1.h"

int main() {
	Livre *maBib= NULL;
	int nbreLivre = 0;
	int tailleP = 0;
	Livre unLivre;

	while (lireLivre(&unLivre)) {
		if (!ajouterLivre(&maBib, unLivre, &nbreLivre, &tailleP))
			perror("Erreur ajout de livre");

		getchar();  // lecture de ligne vide
	}

	afficherBib(maBib, nbreLivre);

	// ça marche pas nsm
	printf("%d\n", nbreLivre);

	exit(0);
}

bool lireLivre(Livre* livre) {
	char ligne[100];

	if (readLimitedLine(livre->titre, MAX_TITRE + 2) <= 0) return false;
	if (readLimitedLine(livre->auteur, MAX_AUTEUR + 2) <= 0) return false;
	if (scanf("%ld\n", &livre->isbn) != 1) return false;
	if (readLimitedLine(livre->editeur, MAX_EDITEUR + 2) <= 0) return false;
	if (scanf("%d\n", &livre->annee_edition) != 1) return false;
	if ((livre->genre = str2genre(ligne)) == -1) return false;
	
	return true;
}

Genre str2genre(char* str) {
	if (!strcmp(str,"Bande dessinée")) return BD;
	if (!strcmp(str,"Poésie")) return PO;
	if (!strcmp(str,"Théâtre")) return TH;
	if (!strcmp(str,"Roman")) return RO;
	if (!strcmp(str,"Roman historique")) return RH;
	if (!strcmp(str,"Littérature française")) return LF;
	if (!strcmp(str,"Littérature étrangère")) return LE;
	if (!strcmp(str,"Sciences")) return SC;
	if (!strcmp(str,"Informatique")) return IN;
	if (!strcmp(str,"Science-fiction")) return SF;
	if (!strcmp(str,"Santé")) return SA;
	if (!strcmp(str,"Histoire")) return HI;
	return -1;
}

char* genre2str (Genre g) {
	switch (g) {
		case BD: return "Bande dessinée";
		case PO: return "Poésie";
		case TH: return "Théâtre";
		case RO: return "Roman";
		case RH: return "Roman historique";
		case LF: return "Littérature française";
		case LE: return "Littérature étrangère";
		case SC: return "Sciences";
		case IN: return "Informatique";
		case SF: return "Science-fiction";
		case SA: return "Santé";
		case HI: return "Histoire";
		default: return NULL;
	}
}

char* livre2str(char* str, Livre livre) {
	sprintf(str, "%-40s %-20s %10ld  %-20s %5d  %s", 
        livre.titre, livre.auteur, livre.isbn, livre.editeur, 
        livre.annee_edition, genre2str(livre.genre)
    );
	return str;
}

void afficherBib(Livre* bib, int tailleBib) {
	char ligne[200];

	for (int i = 0; i < tailleBib; i++) {
		printf("%s", livre2str(ligne, bib[i]));
	}
}

bool ajouterLivre (Livre **bib, Livre l, int *nbreL, int *taille) {
	if (*taille == 0) {
		if ((*bib = (Livre*)malloc((*taille=3)*sizeof(Livre))) == NULL) {
			perror("Malloc");
			return false;
		}
	} else if (*taille == *nbreL) {
		if ((*bib = (Livre*)realloc(*bib, (*taille*=2)*sizeof(Livre))) == NULL) {
			perror("Realloc");
			return false;
		}
	}

	(*bib)[*nbreL] = l;  // copie bit à bit d'une structure Livre!
	(*nbreL)++;
	return true;
}
