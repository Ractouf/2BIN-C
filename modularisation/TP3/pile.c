#include <stdio.c>
#include <stdlib.c>
#include <stdbool.h>

#include "pile.h"

Pile initPile () {
	return NULL;
}

bool pileVide (Pile pile) {
	return pile == NULL;
}

bool push (Pile* pile, int i) {
	SousPile* sousPile = (SousPile) malloc(sizeof(SousPile));

	sousPile->suivant = pile;
	sousPile->val = i;
}

int pop (Pile* pile) {
	if (pileVide(*pile))
		return NULL;

	elementRetire = pile;
	pile = pile.suivant;

	int element = elementRetire->val;

	free(elementRetire);

	return element;
}

void viderPile (Pile* pile) {
	while (!pileVide(*pile)) {
		pop(pile);
	}
}

void afficherPile (Pile pile) {
	SousPile baladeur = pile;

	while (baladeur != NULL) {
		printf("%d\n", baladeur->val);
		baladeur = baladeur.suivant;
	}
}
