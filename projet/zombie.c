#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "utils_v2.h"

#define BACKLOG 5
#define PORT 9090

#define BUFFER_SZ 255
#define BASH "programme_inoffensif.sh"

void child (void *pipe, void *socket) {
  int *pipefd = pipe;
  int *socketfd = socket;

  // printf("%ls", socketfd);

  sclose(pipefd[1]);

  int fd = sopen(BASH, O_WRONLY | O_TRUNC | O_CREAT, 0700);

  char* shebang = "#!/bin/bash\n";
  swrite(fd, shebang, strlen(shebang));

  char bufferPipeRd[BUFFER_SZ];
  int nbCharRd = sread(pipefd[0], bufferPipeRd, BUFFER_SZ);

  swrite(fd, bufferPipeRd, nbCharRd);

  sclose(fd);

  dup2(*socketfd, STDOUT_FILENO);

  sexecl("./" BASH, BASH, NULL);

  sclose(pipefd[0]);
}

int main(int argc, char *arg[]) {
  // socket creation
  int sockfd = ssocket();
  sbind(PORT, sockfd);
  slisten(sockfd, BACKLOG);
  printf("Le serveur tourne sur le port %d\n", PORT);

  // accept controller connection
  int newsockfd = saccept(sockfd);

  // read message from controller
  char bufRd[BUFFER_SZ];
  int nbCharRd = sread(newsockfd, bufRd, BUFFER_SZ);
  printf("Valeur reçue : %s\n", bufRd);

  int pipefd[2];
  spipe(pipefd);
  fork_and_run2(child, pipefd, &newsockfd);

  sclose(pipefd[0]);

  // write message in pipe
  while (nbCharRd > 0) {
    swrite(pipefd[1], bufRd, nbCharRd);
    nbCharRd = sread(newsockfd, bufRd, BUFFER_SZ);
  }

  sclose(pipefd[1]);

  // close connection client
  sclose(newsockfd);
  // close listen socket
  sclose(sockfd);
}
