#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "utils_v2.h"
#include "connection_service.h"

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

int main(int argc, char *argv[]) {
  char* hostname = argv[1];
  if (hostname == NULL) {
    printf("Please provide a hostname\n");
    return 1;
  }

  int numPortsRunning;
  int *portsRunning = getZombiePorts(&numPortsRunning);

  int** portsSockets = (int**) malloc(numPortsRunning * sizeof(int*));

  for (int i = 0; i < numPortsRunning; i++) {
    portsSockets[i] = (int*) malloc(2 * sizeof(int));
  }

  for (int i = 0; i < numPortsRunning; i++) {
    int sockfd = ssocket();
    sconnect(hostname, portsRunning[i], sockfd);

    portsSockets[i][0] = portsRunning[i];
    portsSockets[i][1] = sockfd;
  }

  if (numPortsRunning > 0) {
    while (1) {
      printf("\nVeuillez entrer une commande a executer:\n");

      char command[BUFFER_SZ];
      int nbCharRd = sread(0, command, BUFFER_SZ);

      for (int i = 0; i < numPortsRunning; i++) {
        int port = portsSockets[i][0];
        int sockfd = portsSockets[i][1];

        printf("\nPort: %d\n", port);
        printf("Socket fd: %d\n\n", sockfd);

        printf("Command sent: %s\n", command);
        nwrite(sockfd, command, nbCharRd);

        printf("Output:\n");

        char bufRd[BUFFER_SZ];
        nbCharRd = sread(sockfd, bufRd, BUFFER_SZ);
        swrite(1, bufRd, nbCharRd);
        
        //while (nbCharRd > 0) {
         // swrite(1, bufRd, nbCharRd);
        //  nbCharRd = sread(sockfd, bufRd, BUFFER_SZ);
        //}
      }
    }
  } else {
    printf("none\n");
  }
  
  // close sockets
  for (int i = 0; i < numPortsRunning; i++) {
    sclose(portsSockets[i][1]);
  }

  free(portsSockets);

  return 0;
}
