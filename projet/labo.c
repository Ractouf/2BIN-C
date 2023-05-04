#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils_v2.h"

#include "labo.h"

#define BUFFER_SZ 255

void createZombie() {
  int random = PORTS[randomIntBetween(0, NBR_PORTS - 1)];

  char port[6];
  sprintf(port, "%d", random);

  pid_t pid = sfork();

  if (pid == 0) {
    sexecl("./zombie", "./zombie", port, NULL);
  } else { 
    printf("Zombie process created with PID %d\n", pid);
  }
}

int main() {
  for (int i = 0; i < 2; i++) {
    createZombie();
  }

  sexecl("./controller", "./controller", "127.0.0.1", NULL); 

  return 0;
}
