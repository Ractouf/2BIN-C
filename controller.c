#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "utils_v2.h"

#define BUFFER_SZ 256

bool is_process_running_on_port(int port, const char* process_name) {
  char command[100];
  snprintf(command, sizeof(command), "ss -nlp | grep -w %d | grep -w %s", port, process_name);

  FILE* fp = popen(command, "r");
  if (fp == NULL) {
    perror("Failed to execute command");
    return false;
  }

  char buffer[BUFFER_SZ];
  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    if (strstr(buffer, process_name) != NULL) {
      pclose(fp);
      return true;
    }
  }

  pclose(fp);

  return false;
}

int main(int argc, char *argv[]) {
  char* hostname = argv[1];
  if (hostname == NULL) {
    printf("Please provide a hostname\n");
    return 1;
  }

  int ports[10] = { 10000, 10001, 10002, 10003, 10004, 10005, 10006, 10007, 10008, 10009 }; // example array of ports to check
  const char* process_name = "zombie"; // example process name to search for
  int ports_running[10];
  int num_ports_running = 0;

  printf("Ports running '%s':\n", process_name);

  for (int i = 0; i < 10; i++) {
    if (is_process_running_on_port(ports[i], process_name)) {
      printf("%d\n", ports[i]);
      ports_running[num_ports_running] = ports[i];
      num_ports_running++;
    }
  }

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

  while (1) {
    printf("\nVeuillez entrer une commande a executer:\n");

    char command[BUFFER_SZ];
    int nbCharRd = sread(0, command, BUFFER_SZ);

    command[nbCharRd - 1] = 0;

    for (int i = 0; i < num_ports_running; i++) {
      int port = ports_sockets[i][0];
      int sockfd = ports_sockets[i][1];

      printf("\nPort: %d\n", port);
      printf("Socket fd: %d\n\n", sockfd);

      swrite(sockfd, command, nbCharRd);

      printf("Command sent: %s\n\n", command);

      printf("Output:\n");
      
      char bufRd[BUFFER_SZ];
      int nbCharRd = sread(sockfd, bufRd, BUFFER_SZ);
      swrite(1, bufRd, nbCharRd);
      
      
      //int nbCharRd;
      //do {
      //  nbCharRd = sread(sockfd, bufRd, BUFFER_SZ);
      //  if (nbCharRd > 0) {
      //    swrite(1, bufRd, nbCharRd);
      //  }
      //} while (nbCharRd > 0);
    }
  }

  // close sockets
  for (int i = 0; i < num_ports_running; i++) {
    sclose(ports_sockets[i][1]);
  }

  free(ports_sockets);

  return 0;
}
