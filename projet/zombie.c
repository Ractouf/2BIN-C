#include <string.h>
#include <fcntl.h>

#include "utils_v2.h"

#define BACKLOG 5
#define PORT 9090

#define TAILLE 255
#define BASH "programme_inoffensif.sh"

void child (void *argv) {
  int *pipefd = argv;

  sclose(pipefd[1]);

  int fd = open(BASH, O_WRONLY | O_TRUNC | O_CREAT, 0700);
  checkNeg(fd, "Error opening file");

  char* shebang = "#!/bin/bash\n";
  swrite(fd, shebang, strlen(shebang));

  char bufferPipeRd[TAILLE];
  int nbCharRd = sread(pipefd[0], bufferPipeRd, TAILLE);

  swrite(fd, bufferPipeRd, nbCharRd);
}

int main(int argc, char *arg[]) {
  // socket creation
  int sockfd = ssocket();
  sbind(PORT, sockfd);
  slisten(sockfd, BACKLOG);
  printf("Le serveur tourne sur le port %d\n", PORT);
  
  // accept client connection
  int newsockfd = saccept(sockfd);
  
  // read message from client
  char bufRd[TAILLE];
  int nbCharRd = sread(newsockfd, bufRd, TAILLE);
  printf("Valeur reçue : %s\n", bufRd);
  
  int pipefd[2];
  spipe(pipefd);

  pid_t childId = fork_and_run1(child, pipefd);

  printf("%d\n", childId);
  printf("parent\n");

  sclose(pipefd[0]);

  while (nbCharRd > 0) {
    swrite(pipefd[1], bufRd, nbCharRd);
    nbCharRd = sread(0, bufRd, TAILLE);
  }

  sclose(pipefd[1]);

  // close connection client
  sclose(newsockfd);
  // close listen socket
  sclose(sockfd);
}