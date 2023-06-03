#include "crypt.h"

static char* rot13(char* msg) {
   int sz = strlen(msg);

   char* res = malloc((sz + 1) * sizeof(char));
   if (res == NULL) {
      perror("ROT13 00");
      exit(23);
   }

   char c;
   int i = sz;
   char* m1 = msg;
   char* m2 = res;
   while(i != 0) {
      i--;
      if (isalpha(*m1)) {
         c = islower(*m1) ? 'a' : 'A';
         *m1 -= c;
         *m2 = (*m1 + 13) % 26 + c;
         *m1 += c;
      } else {
         *m2 = *m1;
      }
      m1++;
      m2++;
   }
  
   *m2 = '\0';
   return res;
}

char* encryptRot13 (char* msg) {
   return rot13(msg);
}

char* decryptRot13 (char* msg) {
   return rot13(msg);
}

char* encryptPolybe(char* msg) {
    int sz = strlen(msg);

    char* crypt = (char*) malloc(sz * 2 * sizeof(char));
    if (crypt == NULL) {
        perror("ça a pas marché");
        exit(1);
    }

    int sizeTab = 0;

    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                if (toupper(msg[i]) == square[j][k]) {
                    crypt[sizeTab++] = j + '0' + 1;
                    crypt[sizeTab++] = k + '0' + 1;
                }
            }
        }
    }

    return crypt;
}

char* decryptPolybe(char* msg) {
    int sz = strlen(msg);

    char* decrypt = (char*) malloc(sz / 2 * sizeof(char));
    if (decrypt == NULL) {
        perror("ça a pas marché");
        exit(1);
    }

    int sizeTab = 0;

    for (int i = 0; i < sz; i = i + 2) {
        decrypt[sizeTab] = square[msg[i] - '0' - 1][msg[i + 1] - '0' - 1];
        sizeTab++;
    }

    return decrypt;
}

char* encryptMorse(char* msg) {
    int sz = strlen(msg);

    char* crypt = (char*) malloc(sz * 4 * sizeof(char));
    if (crypt == NULL) {
        perror("ça a pas marché");
        exit(1);
    }

    int sizeTab = 0;

    for (int i = 0; i < sz; i++) {
        if (msg[i] == ' ') {
            strcpy(crypt + sizeTab, "   ");
            sizeTab += 3;
        } else {
            if (isalpha(msg[i])) {
                int index = toupper(msg[i]) - 'A';

                if (index >= 0 && index < 26) {
                    strcpy(crypt + sizeTab, alpha[index]);
                    sizeTab += strlen(alpha[index]);

                    crypt[sizeTab++] = ' ';
                }
            }
        }
    }

    return crypt;
}

// gère pas les phrases
char* decryptMorse(char* msg) {
    int sz = strlen(msg);

    char* decrypt = (char*) malloc(sz * sizeof(char));
    if (decrypt == NULL) {
        perror("ça a pas marché");
        exit(1);
    }

    int sizeTab = 0;

    char* token = strtok(msg, " ");

    while (token != NULL) {
        for (int i = 0; i < 26; i++) {
            if (strcmp(token, alpha[i]) == 0) {
                decrypt[sizeTab++] = 'A' + i;
                break;
            }
        }
        
        token = strtok(NULL, " ");
    }

    return decrypt;
}
