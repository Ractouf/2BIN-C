#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "crypt.h"

static char square[8][8] = {
   {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'},
   {'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'},
   {'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X'},
   {'Y', 'Z', '0', '1', '2', '3', '4', '5'},
   {'6', '7', '8', '9', ' ', '!', '"', '#'},
   {'$', '%', '&', '\'', '(', ')', '*', '+'},
   {',', '-', '.', '/', ':', ';', '<', '='},
   {'>', '?', '@', '[', '\\', ']', '^', '_'}
};

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