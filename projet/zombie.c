#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "utils_v2.h"
#include "connection_service.h"

void child(void *newsockfd) {
  int socketfd = *(int*) newsockfd;

  dup2(socketfd, STDIN_FILENO);
  dup2(socketfd, STDOUT_FILENO);
  dup2(socketfd, STDERR_FILENO);

  sclose(socketfd);

  sexecl("/bin/bash", BASH, NULL);
}

int main(int argc, char *arg[]) {

  int PORT;
  if (arg[1] != NULL) {
    PORT = atoi(arg[1]);
  } else {
    int random = randomIntBetween(0, NUM_PORTS - 1);
    PORT = PORT_TABLE[random];
  }

  int sockfd = createSocket(PORT);

  int newsockfd;
  
  while(1) {
    newsockfd = accept(sockfd, NULL, NULL);

    printf("newsockfd: %d\n", newsockfd);

    if (newsockfd == -1) {
      // BUTER LES PTN D4ENFANTS venant du tableau de pid
      exit(1);
    } else if (newsockfd > 0) {
      printf("Client connected.\n");
      fork_and_run1(child, &newsockfd);
    }
  }
}
