#include <string.h>

#include "utils_v2.h"

#define LOCAL_HOST "127.0.0.1"
#define SERVER_PORT 9090

int main(int argc, char *arg[]) {
  // socket creation
  int sockfd = ssocket();
  
  // prepare socket to connect
  sconnect(LOCAL_HOST, SERVER_PORT, sockfd);
  
  // write message to server
  char* str = "ls -l";
  printf("Client envoie le string au serveur\n");
  swrite(sockfd, str, strlen(str));
  
  // close socket
  sclose(sockfd);
  return 0;
}