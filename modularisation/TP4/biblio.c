#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "biblio.h"
#include "utils_v1.h"

#define BUF_SIZE TITRE + 2

static char* mesGenres[] = {
	"Bande dessinée", "Poésie", "Théâtre", "Roman", "Roman historique", "Littérature française", 
	"Littérature étrangère", "Sciences", "Informatique", "Science-fiction", "Santé", "Histoire", NULL
};

bool lireLivre(struct Livre *livre) {
	char ligne[BUF_SIZE];
	if (readLimitedLine (ligne, TITRE + 2) <= 0) return false;
	strcpy(livre->titre, ligne);

	if (readLimitedLine(ligne, AUTEUR + 2) <= 0) return false;
	strcpy(livre->auteur, ligne);

	if(scanf("%ld\n", &livre->isbn) != 1) return false;

	if (readLimitedLine(ligne, EDITEUR + 2) <= 0) return false;
	strcpy(livre->editeur, ligne);

	if (scanf("%d\n", &livre->anneeEdition) != 1) return false;

	if (readLimitedLine(ligne, BUF_SIZE) <= 0) return false;
	if ((livre->genre = str2genre(ligne)) == -1) return false;

	return true;
}

enum Genre str2genre(char* genre) {
	for (enum Genre i = 0; i < GENRES_NUM; i++) {
		if (!strcmp(genre, mesGenres[i])) {
			return i;
		}
	}

	return -1;
}

char* genre2str (enum Genre genre) {
	int maxGenre = sizeof(mesGenres) / sizeof(char*) - 1;

	if (genre < 0 || genre >= maxGenre)
		return NULL;

	return mesGenres[genre];
}

char* livre2str (char *s, struct Livre l) {
	sprintf(s, "%-40s %-20s %10ld  %-20s %5d  %s", 
			l.titre, l.auteur, l.isbn, l.editeur, l.anneeEdition, genre2str(l.genre));
	return s;
}

void afficherBib (const struct Livre* bib, int t) {
	char ligne[MAX_LIGNE_LIVRE];
	printf("Voici ma bib de %d livres:\n", t);

	for (int i = 0; i < t; i++) {
		printf("\t%s\n", livre2str(ligne, bib[i]));
	}

	printf("---------------------------\n");
}

bool ajouterLivre (struct Livre **bib, struct Livre l, int *nbreL, int *taille) {
	if (*taille == 0) {
		if ((*bib = (struct Livre*) malloc((*taille = 3) * sizeof(struct Livre))) == NULL) {
			perror("Malloc");
			return false;
		}
	} else if (*taille == *nbreL) {
		if ((*bib = (struct Livre*) realloc(*bib, (*taille *= 2) * sizeof(struct Livre))) == NULL) {
			perror("Realloc");
			return false;
		}
	}
	(*bib)[*nbreL] = l;  // copie bit à bit d'une structure Livre!
	(*nbreL)++;
	return true;
}

bool lireFichier(FILE* file, struct Livre** bib, int* nbreL, int* taille) {
	struct Livre tmp[BUF_SIZE];
	int lu = BUF_SIZE;

	while(lu == BUF_SIZE) {
		lu = fread(tmp, sizeof(struct Livre), BUF_SIZE, file);
		
		for (int i = 0; i < lu; i++) {
			ajouterLivre(bib, tmp[i], nbreL, taille);
		}
	}

	return feof(file);
}

bool ecrireFichier(FILE* file, struct Livre* bib, int taille) {
	return fwrite(bib, sizeof(struct Livre), taille, file) != BUF_SIZE;
}
