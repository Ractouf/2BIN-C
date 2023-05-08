#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "utils_v2.h"
#include "controller.h"

#define BUFFER_SZ 256

bool is_process_running_on_port(int port) {
  char command[100];
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

int* get_zombie_ports(int *nb) {
  int* ports_running = (int *) malloc(10 * sizeof(int));
  int num_ports_running = 0;

  printf("Ports running '%s':\n", PROCESS);

  for (int i = 0; i < 10; i++) {
    if (is_process_running_on_port(PORTS[i])) {
      printf("%d\n", PORTS[i]);
      ports_running[num_ports_running] = PORTS[i];

      num_ports_running++;
    }
  }

  *nb = num_ports_running;
  return ports_running;
}

int main(int argc, char *argv[]) {
  char* hostname = argv[1];
  if (hostname == NULL) {
    printf("Please provide a hostname\n");
    return 1;
  }

  int num_ports_running;
  int *ports_running = get_zombie_ports(&num_ports_running);

  int** ports_sockets = (int**) malloc(num_ports_running * sizeof(int*));

  for (int i = 0; i < num_ports_running; i++) {
    ports_sockets[i] = (int*) malloc(2 * sizeof(int));
  }

  for (int i = 0; i < num_ports_running; i++) {
    int sockfd = ssocket();
    sconnect(hostname, ports_running[i], sockfd);

    ports_sockets[i][0] = ports_running[i];
    ports_sockets[i][1] = sockfd;
  }

  if (num_ports_running > 0) {
    while (1) {
      printf("\nVeuillez entrer une commande a executer:\n");

      char command[BUFFER_SZ];
      int nbCharRd = sread(0, command, BUFFER_SZ);

      for (int i = 0; i < num_ports_running; i++) {
        int port = ports_sockets[i][0];
        int sockfd = ports_sockets[i][1];

        printf("\nPort: %d\n", port);
        printf("Socket fd: %d\n\n", sockfd);

        printf("Command sent: %s\n", command);
        swrite(sockfd, command, nbCharRd);

        printf("Output:\n");
      }
    }
  } else {
    printf("none\n");
  }
  
  // close sockets
  for (int i = 0; i < num_ports_running; i++) {
    sclose(ports_sockets[i][1]);
  }

  free(ports_sockets);

  return 0;
}
