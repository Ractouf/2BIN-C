#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <poll.h>

#include "utils_v2.h"
#include "connection_service.h"

int main(int argc, char *argv[]) {
  char* hostname = argv[1];
  if (hostname == NULL) {
    printf("Please provide a hostname\n");
    return 1;
  }

  int portsRunning[NUM_PORTS];
  int numPortsRunning = getZombiePorts(&portsRunning);

  int** portsSockets = (int**) malloc(numPortsRunning * sizeof(int*));

  for (int i = 0; i < numPortsRunning; i++) {
    portsSockets[i] = (int*) malloc(2 * sizeof(int));
  }

  for (int i = 0; i < numPortsRunning; i++) {
    int sockfd = ssocket();
    sconnect(hostname, portsRunning[i], sockfd);

    portsSockets[i][0] = portsRunning[i];
    portsSockets[i][1] = sockfd;
  }

  if (numPortsRunning > 0) {
    int childId = sfork();

    if (childId != 0) {
      // PAPA
      while (1) {
        char command[BUFFER_SZ];
        int nbCharRd = sread(0, command, BUFFER_SZ);

        for (int i = 0; i < numPortsRunning; i++) {
          int port = portsSockets[i][0];
          int sockfd = portsSockets[i][1];

          printf("\nPort: %d\n\n", port);

          nwrite(sockfd, command, nbCharRd);
        }
      }
    } else {
      // PA PAPA
      struct pollfd fds[NUM_PORTS];
      int timeout = 10;

      for (int i = 0; i < numPortsRunning; i++) {
        int sockfd = portsSockets[i][1];

        fds[i].fd = sockfd;
        fds[i].events = POLLIN;
      }

      while (1) {
        int ret = spoll(fds, numPortsRunning, timeout);

        if (ret > 0) {
          for (int i = 0; i < numPortsRunning; i++) {
            if (fds[i].revents & POLLIN) {
              char bufRd[BUFFER_SZ];
              int nbCharRd = sread(fds[i].fd, bufRd, BUFFER_SZ);

              swrite(1, bufRd, nbCharRd);
            }
          }
        }
      }
    }
  } else {
    printf("none\n");
  }

  // close sockets
  for (int i = 0; i < numPortsRunning; i++) {
    sclose(portsSockets[i][1]);
  }

  free(portsSockets);

  return 0;
}
