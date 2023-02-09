#ifndef _PILE_H_
	#define _PILE_H_

	#include <stdbool.h>

	#define TITRE 128
	#define AUTEUR 80
	#define EDITEUR 50

	enum Genre { 
		BANDE_DESSINEE, 
		POESIE, 
		THEATRE, 
		ROMAN, 
		ROMAN_HISTORIQUE, 
		LITTERATURE_FRANCAISE, 
		LITTERATURE_ETRANGERE, 
		SCIENCES, 
		INFORMATIQUE, 
		SCIENCE_FICTION, 
		SANTE, 
		HISTOIRE 
	};

	struct Livre {
		char titre[TITRE + 1];
		char auteur[AUTEUR + 1];
		long isbn;
		char editeur[EDITEUR + 1];
		int anneeEdition;
		enum Genre genre;
	};

	bool lireLivre(struct Livre* livre);
	enum Genre str2genre(char* genre);
	char* genre2str(enum Genre genre);
	char* livre2str(struct Livre livre);
	void afficherBib(struct Livre* livres, int sz);
	bool ajouterLivre(struct Livre livre, struct Livre** livres, int* szl, int* szp);
#endif
