#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

char* encrypt (char* msg) {
   return rot13(msg);
}

char* decrypt (char* msg) {
   return rot13(msg);
}
