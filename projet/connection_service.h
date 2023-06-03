#ifndef _CONNECTION_SERVICE_H_
#define _CONNECTION_SERVICE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdbool.h>
#include <poll.h>

#include "utils_v2.h"

#define SERVER_IP "127.0.0.1"
#define NUM_PORTS 10
#define BUFFER_SZ 1024
#define BACKLOG 5
#define PROCESS "zombie"
#define BASH "programme_inoffensif"

static const int PORT_TABLE[NUM_PORTS] = {
    10000, 10001, 10002, 10003, 10004,
    10005, 10006, 10007, 10008, 10009
};

int createSocket(int PORT);

#endif