#include "crypt.h"
#include "utils_v1.h"

int main() {
	char* line = readLine();

	printf("The crypted is : %s\n", line);

	line = decryptPolybe(line);

	printf("The decrypted line is : %s\n", line);

	exit(0);
}