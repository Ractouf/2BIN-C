#ifndef _PILE_H_
	#define _PILE_H_

	#include <stdbool.h>

	#define TITRE 128
	#define AUTEUR 80
	#define EDITEUR 50
	#define MAX_LIGNE_LIVRE (TITRE + AUTEUR + EDITEUR + 50)

	enum Genre {
		BD, PO, TH, RO, RH, LF, LE, SC, IN, SF, SA, HI, GENRES_NUM
	};

	struct Livre {
		char titre[TITRE + 1];
		char auteur[AUTEUR + 1];
		long isbn;
		char editeur[EDITEUR + 1];
		int anneeEdition;
		enum Genre genre;
	};

	bool lireLivre(struct Livre *livre);
	enum Genre str2genre(char* genre);
	char* genre2str(enum Genre genre);
	char* livre2str(char* s, struct Livre livre);
	void afficherBib(const struct Livre* livres, int sz);
	bool ajouterLivre(struct Livre** bib, struct Livre livre, int* nbreL, int* taille);
	bool lireFichier(FILE* file, struct Livre** bib, int* nbreL, int* taille);
	bool ecrireFichier(FILE* file, struct Livre* bib, int taille);
#endif
