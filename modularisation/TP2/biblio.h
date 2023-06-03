#ifndef _BIBLIO_H_
#define _BIBLIO_H_

#include <stdbool.h>

#define MAX_TITRE 128
#define MAX_AUTEUR 80
#define MAX_EDITEUR 50

typedef enum {
	BD, PO, TH, RO, RH, LF, LE, SC, IN, SF, SA, HI
} Genre;

typedef struct {
	char titre[MAX_TITRE];
	char auteur[MAX_AUTEUR];
	long isbn;
	char editeur[MAX_EDITEUR];
	int annee_edition;
	Genre genre;
} Livre;

bool lireLivre(Livre* livre);

Genre str2genre(char* str);

char* genre2str(Genre genre);

char* livre2str(char* str, Livre livre);

void afficherBib(Livre* bib, int tailleBib);

bool ajouterLivre(Livre **bib, Livre l, int *nbreL, int *taille);

#endif