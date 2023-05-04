#include <string.h>

#include "utils_v2.h"

#define LOCAL_HOST "127.0.0.1"
#define SERVER_PORT 9090

#define BUFFER_SZ 255

int main(int argc, char *arg[]) {
  int nbCharRd;

  // socket creation
  int sockfd = ssocket();
    
  // prepare socket to connect
  sconnect(LOCAL_HOST, SERVER_PORT, sockfd);

  char command[BUFFER_SZ];
  nbCharRd = sread(0, command, BUFFER_SZ);
  command[nbCharRd - 1] = 0;
  swrite(sockfd, command, nbCharRd);

  // char* str = "ls -l";
  // printf("Client envoie le string au serveur\n");
  // swrite(sockfd, str, strlen(str));

  char bufRd[BUFFER_SZ];
  nbCharRd = sread(sockfd, bufRd, BUFFER_SZ);

  while(nbCharRd > 0) {
    swrite(1, bufRd, nbCharRd);
    nbCharRd = sread(sockfd, bufRd, BUFFER_SZ);
  }
  
  // close socket
  sclose(sockfd);
  return 0;
}
