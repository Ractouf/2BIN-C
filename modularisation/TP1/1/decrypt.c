#include "crypt.h"
#include "utils_v1.h"

int main() {
	char* line = readLine();

	printf("The crypted line is : %s\n", line);

	line = decrypt(line);

	printf("The decrypted line is : %s\n", line);

	exit(0);
}