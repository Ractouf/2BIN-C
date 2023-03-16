#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inscriptionRequest.h"

#define FILENAME "DemandesInscriptions.bin"

int main()
{
    char* lastnames[] = {"DRATHEY", "OCHON", "UZI", "TERRIEUR", "TERRIEUR"};
    char* firstnames[] = {"Daisy", "Paul", "Jack", "Alain", "Alex"};
    int years[] = {3, 2, 1, 0, 1};

    printf("Création du fichier binaire %s\n", FILENAME);
	FILE *file;
	file = fopen(FILENAME, "wb");    
    
	InscriptionRequest ir;
    for (int i=0; i<5; i++) {
        strcpy(ir.name, lastnames[i]);
        strcpy(ir.firstname, firstnames[i]);
        ir.nbYearPastInEducation = years[i];
        
        fwrite(&ir, sizeof(ir), 1, file);
        printf("Ecriture de structure dans %s\n", FILENAME);
    }

	fclose(file);
}
