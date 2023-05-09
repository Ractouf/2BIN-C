#include <string.h>
#include <stdlib.h>

#include "utils_v2.h"
#include "connection_service.h"

int createSocket(unsigned short PORT) {
  int sockfd = ssocket();
  sbind(PORT, sockfd);
  slisten(sockfd, BACKLOG);
  printf("Le serveur tourne sur le port %d\n", PORT);

  return sockfd;
}

int* getZombiePorts(int *nb) {
  int* portsRunning = (int*) malloc(NUM_PORTS * sizeof(int));
  int numPortsRunning = 0;

  printf("Ports running '%s':\n", PROCESS);

  for (int i = 0; i < NUM_PORTS; i++) {
    if (isProcessRunningOnPort(PORT_TABLE[i])) {
      printf("%d\n", PORT_TABLE[i]);
      portsRunning[numPortsRunning] = PORT_TABLE[i];

      numPortsRunning++;
    }
  }

  *nb = numPortsRunning;
  return portsRunning;
}

bool isProcessRunningOnPort(int port) {
  char command[BUFFER_SZ];
  snprintf(command, sizeof(command), "ss -nlp | grep -w %d | grep -w %s", port, PROCESS);

  FILE* fp = popen(command, "r");
  if (fp == NULL) {
    perror("Failed to execute command");
    return false;
  }

  char buffer[BUFFER_SZ];
  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    if (strstr(buffer, PROCESS) != NULL) {
      pclose(fp);
      return true;
    }
  }

  pclose(fp);

  return false;
}
