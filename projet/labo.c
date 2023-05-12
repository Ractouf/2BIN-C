#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils_v2.h"

#include "connection_service.h"

void createZombie() {
  int random = PORT_TABLE[randomIntBetween(0, NUM_PORTS - 1)];

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

  char bufRd[BUFFER_SZ];
  sread(1, bufRd, BUFFER_SZ);

  return 0;
}

/*
ctrl D -> kill zombies et enfants

accept et pas saccept
si ret -1 -> kill les bash car signal
*/