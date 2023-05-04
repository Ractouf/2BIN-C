#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "utils_v2.h"

#define BACKLOG 5
#define PORT 9090

int main(int argc, char *arg[]) {
  // socket creation
  int sockfd = ssocket();
  sbind(PORT, sockfd);
  slisten(sockfd, BACKLOG);
  printf("Le serveur tourne sur le port %d\n", PORT);
  
  // accept client connection
  int newsockfd = saccept(sockfd);
  
  // read message from client
  int val;
  sread(newsockfd, &val, sizeof(int));
  printf("Valeur reçue : %i\n", val);
  
  // close connection client
  sclose(newsockfd);
  // close listen socket
  sclose(sockfd);
}