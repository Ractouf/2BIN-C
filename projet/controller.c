// Projet de LAS 2023
// Auteurs: 
//   - D'haeyere Corentin
//   - Lapinski Damien
//   - Vandeputte Francois

#include "connection_service.h"

struct IpPortFd {
  char ip[16];
  int port;
  int fd;
};

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <...hostnames>\n", argv[0]);
    exit(1);
  }
  
  char** hostnames = (char**) malloc((argc - 1) * sizeof(char*));
  for (int i = 1; i < argc; i++) {
    hostnames[i - 1] = argv[i];
  }

  struct IpPortFd *ipPortFd = (struct IpPortFd*) malloc(((argc - 1) * NUM_PORTS) * sizeof(struct IpPortFd));
  int nbConnections = 0;

  for (int i = 0; i < argc - 1; i++) {
    for (int j = 0; j < NUM_PORTS; j++) {
      int sockfd = ssocket();
      
      int response = sconnect(hostnames[i], PORT_TABLE[j], sockfd);
      
      if (!response) {
        strcpy(ipPortFd[nbConnections].ip, hostnames[i]);
        ipPortFd[nbConnections].port = PORT_TABLE[j];
        ipPortFd[nbConnections].fd = sockfd;

        nbConnections ++;
      }
    }
  }

  printf("Running zombies:\n");
  for (int i = 0; i < nbConnections; i++) {
    printf("%s:%d\n", ipPortFd[i].ip, ipPortFd[i].port);
  }

  if (nbConnections > 0) {
    int childId = sfork();

    if (childId != 0) {
      // PAPA
      while (1) {
        char command[BUFFER_SZ];
        int nbCharRd = sread(0, command, BUFFER_SZ);

        if (nbCharRd == 0) {
          for (int i = 0; i < nbConnections; i++) {
            sclose(ipPortFd[i].fd);
          }

          free(ipPortFd);
          free(hostnames);

          skill(childId, SIGKILL);
          swaitpid(childId, NULL, 0);

          exit(0);
        }

        for (int i = 0; i < nbConnections; i++) {
          int sockfd = ipPortFd[i].fd;

          swrite(sockfd, command, nbCharRd);
        }
      }
    } else {
      // PA PAPA
      struct pollfd fds[NUM_PORTS];
      int timeout = 10;

      for (int i = 0; i < nbConnections; i++) {
        int sockfd = ipPortFd[i].fd;

        fds[i].fd = sockfd;
        fds[i].events = POLLIN;
      }

      while (1) {
        int ret = spoll(fds, nbConnections, timeout);

        if (ret > 0) {
          for (int i = 0; i < nbConnections; i++) {
            if (fds[i].revents & POLLIN) {
              char bufRd[BUFFER_SZ];
              int nbCharRd = sread(fds[i].fd, bufRd, BUFFER_SZ);

              if (nbCharRd == 0) {
                skill(getppid(), SIGTERM);
                break;
              }

              swrite(1, bufRd, nbCharRd);
            }
          }
        }
      }
    }
  } else {
    printf("none\n");
  }

  return 0;
}
