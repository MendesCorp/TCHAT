#pragma once

#define MAX_USERS 50
int users[MAX_USERS];
int serv_fd; 
int user_fd[MAX_USERS];
int compteur_clients = 0;

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

#define SERV_PORT 4329
#define BUF_SIZE 500
#include "fonctions.c"
