#include <stdio.h>
#include <stdlib.h>

#include "pile.h"

int main() {
	Pile pile = initPile();
	push(&pile, 1);
	push(&pile, 2);
	push(&pile, 4);

	afficherPile(pile);

	pop(&pile);

	afficherPile(pile);

	viderPile(&pile);
}