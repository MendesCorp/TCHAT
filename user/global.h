#pragma once

#define MAX_USERS 2077
int users[MAX_USERS];
int user_fd;
int serv_fd; 
int identifiants_clients[MAX_USERS];

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
// #include <dirent.h> // listing des fichiers
// #include <fcntl.h>  // gérer ls fichiers
#include <sys/stat.h> 
#include <pthread.h> // pr ls threads

#define USER_PORT 5892
#define SERV_PORT 1999

#define BUF_SIZE 500
#include "fonctions.c"