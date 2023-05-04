#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "utils_v2.h"

#define LOCAL_HOST "127.0.0.1"
#define SERVER_PORT 9090
#define VAL 7

int main(int argc, char *arg[]) {
  // socket creation
  int sockfd = ssocket();
  
  // prepare socket to connect
  sconnect(LOCAL_HOST, SERVER_PORT, sockfd);
  
  // write message to server
  int val = VAL;
  printf("Client envoie la valeur 7 au serveur\n");
  swrite(sockfd,&val,sizeof(int));
  
  // close socket
  sclose(sockfd);
  return 0;
}