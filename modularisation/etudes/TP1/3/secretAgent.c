#include "crypt.h"
#include "utils_v1.h"

void encrypt(int choise2) {
	printf("Entrez une ligne a crypter: ");
	char* line = readLine();

	switch (choise2) {
		case 1:
			line = encryptRot13(line);

			printf("The crypted line is : %s\n", line);
			break;
		case 2:
			line = encryptPolybe(line);

			printf("The crypted line is : %s\n", line);
			break;
		case 3:
			line = encryptMorse(line);

			printf("The crypted line is : %s\n", line);
			break;
		default: 
			break;
	}
}

void decrypt(int choise2) {
	printf("Entrez une ligne a décrypter: ");
	char* line = readLine();

	switch (choise2) {
		case 1:
			line = decryptRot13(line);

			printf("The crypted line is : %s\n", line);
			break;
		case 2:
			line = decryptPolybe(line);

			printf("The crypted line is : %s\n", line);
			break;
		case 3:
			line = decryptMorse(line);

			printf("The crypted line is : %s\n", line);
			break;
		default: 
			break;
	}
}

int main() {
	char* line;
	int choise1;
	int choise2;

	do {
		printf("1. Cryptage\n2. Décreptage\nEntrez votre choix (Ctrl-D pour terminer) :\n");
		line = readLine();
		choise1 = line[0] - '0';
	} while (choise1 < 1 || choise1 > 2);

	do {
		printf("1. ROT13\n2. Polybe\n3. Morse\nEntrez votre choix :\n");
		line = readLine();
		choise2 = line[0] - '0';
	} while (choise2 < 1 || choise2 > 3);

	switch (choise1) {
		case 1: 
			encrypt(choise2);
			break;
		case 2:
			decrypt(choise2);
			break;
		default: 
			break;
	}
}
