#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "utils_v2.h"
#include "connection_service.h"

int childs_pid[100];
int num_children = 0;

void child(void *newsockfd) {
  int socketfd = *(int*) newsockfd;

  dup2(socketfd, STDIN_FILENO);
  dup2(socketfd, STDOUT_FILENO);
  dup2(socketfd, STDERR_FILENO);

  sclose(socketfd);

  sexecl("/bin/bash", BASH, NULL);
}

void sigterm_handler(int sig) {
  for (int i = 0; i < num_children; i++) {
    kill(childs_pid[i], SIGTERM);
  }
  exit(0);
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

  struct sigaction action = {0};
  action.sa_handler = sigterm_handler;
  sigaction(SIGTERM, &action, NULL);
  
  while(1) {
    newsockfd = accept(sockfd, NULL, NULL);

    if (newsockfd == -1) {
      printf("newsockfd négatif\n");
      break;
    } else {
      printf("Client connected.\n");
      int childId = fork_and_run1(child, &newsockfd);

      if (childId > 0 && num_children < 100) {
        childs_pid[num_children++] = childId;
      }
    }
  }

  sclose(newsockfd);
  sclose(sockfd);

  return 0;
}
