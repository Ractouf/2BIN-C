#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "pile.h"

Pile initPile () {
	return NULL;
}

bool pileVide (Pile pile) {
	return pile == NULL;
}

bool push (Pile *pile, int i) {
	SousPile* sousPile = (SousPile*) malloc(sizeof(SousPile));
	if (sousPile == NULL) {
		return false;
	}

	sousPile->suivant = *pile;
	sousPile->val = i;
	return true;
}

int pop (Pile *pile) {
	if (pileVide(*pile))
		return -1;

	Pile elementRetire = *pile;
	*pile = (*pile)->suivant;

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
	while (pile != NULL) {
		printf("%d\n", pile->val);
		pile = pile->suivant;
	}
}
