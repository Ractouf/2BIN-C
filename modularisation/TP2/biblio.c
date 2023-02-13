#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "utils_v1.h"

#define BUF_SIZE MAX_TITRE + 2
#define NBR_GENRES 12

char* mesGenres[NBR_GENRES] = {
	"Bande dessinée", "Poésie", "Théâtre", "Roman", "Roman historique", "Littérature française", 
	"Littérature étrangère", "Sciences", "Informatique", "Science-fiction", "Santé", "Histoire"
}

bool lireLivre(struct Livre* livre) {
	char ligne[BUF_SIZE];
	if (readLimitedLine (ligne, MAX_TITRE + 2) <= 0) return false;
	strcpy(livre->titre, ligne);

	if (readLimitedLine(ligne, MAX_AUTEUR + 2) <= 0) return false;
	strcpy(livre->auteur, ligne);

	if(scanf("%ld\n", &livre->isbn) != 1) return false;

	if (readLimitedLine(ligne, MAX_EDITEUR + 2) <= 0) return false;
	strcpy(livre->editeur, ligne);

	if (scanf("%d\n", &livre->anneeEdition) != 1) return false;

	if (readLimitedLine(ligne, BUF_SIZE) <= 0) return false;
	if ((livre->genre = str2genre(ligne)) == -1) return false;

	return true;
}

enum Genre str2genre(char* genre) {
	for (int i = 0; i < NBR_GENRES; i++) {
		if (genre == mesGenres[i]) {
			return enum Genre[i];
		}
	}

	return -1;
}