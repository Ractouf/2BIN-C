#ifndef _PILE_H_
	#define _PILE_H_

	#include <stdbool.h>

	typedef struct SousPile {
		int val;
		struct SousPile* suivant;
	} SousPile;

	typedef SousPile* Pile;

	Pile initPile ();
	bool pileVide (Pile pile);
	bool push (Pile* pile, int i);
	int pop (Pile* pile);
	void viderPile (Pile* pile);
	void afficherPile (Pile pile);
#endif