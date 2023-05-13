#include <string.h>

#include "utils_v2.h"
#include "connection_service.h"

int createSocket(int PORT) {
  int sockfd = ssocket();
  sbind(PORT, sockfd);
  slisten(sockfd, BACKLOG);
  printf("Le zombie tourne sur le port %d\n", PORT);

  return sockfd;
}
