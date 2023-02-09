#include <stdio.h>
#include <stdlib.h>
#include <bool.h>

#include "utils_v1.h"

bool lireLivre(struct Livre* livre) {
	readLimitedLine (livre.titre, );
	readLimitedLine(livre.auteur, );
	scanf("%d", livre.isbn);
	readLimitedLine(livre.editeur, );
	scanf("%d", livre.anneeEdition);
	readLimitedLine();
}