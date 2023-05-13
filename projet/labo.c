#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils_v2.h"
#include "connection_service.h"

pid_t zombie_pids[2];

int main() {
  for (int i = 0; i < 2; i++) {
    int childId = sfork();
    
    if (childId != 0) {
      // PAPA
      zombie_pids[i] = childId;
    } else {
      // PA PAPA
      sexecl("./zombie", "./zombie", NULL);
    }
  }

  char bufRd[BUFFER_SZ];
  while (1) {
    if ((sread(1, bufRd, BUFFER_SZ) == 0)) {
      break;
    }
  }

  for (int i = 0; i < 2; i++) {
    skill(zombie_pids[i], SIGKILL);
  }

  return 0;
}

/*
accept et pas saccept
si ret -1 -> kill les bash car signal
*/