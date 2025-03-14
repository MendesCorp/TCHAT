#pragma once

#define MAX_USERS 50


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
#include <errno.h>

int serv_fd;
int compteur_clients = 0;

typedef struct user
{
    char name[255];
    int fd;
    int id_room;
} t_user;

t_user users[MAX_USERS];

typedef struct message
{
    char name[255];
    int id_room; // tag du salon
    char message[1000];
} t_message;

// fichiers avec toutes les fonctions
#include "user_socket.c"
#include "send.c"
#include "recev.c"
=======
#include <sys/stat.h> 
#include <pthread.h> // pr ls threads
#include <errno.h>

int serv_fd; 
int compteur_clients = 0;

typedef struct user {
    char name[255];
    int user_fd[MAX_USERS];
    int id_room;
}t_user;

t_user users[MAX_USERS];

typedef struct message {
    char name[255];
    int id_room;        //tag du salon
    char message[1000];
}t_message;

//fichiers avec toutes les fonctions
#include "user_sock.c"
#include "send.c"
#include "recv.c"

