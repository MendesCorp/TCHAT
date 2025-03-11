#pragma once 


#include "global.h"

/*
initialisation du fichier socket serveur
*/

int initSocket(int port_serv) 
{
    int serv_fd = socket(AF_INET, SOCK_STREAM, 0); perror("socket");
    if(serv_fd == -1) return EXIT_FAILURE;

    struct sockaddr_in serv = {
        .sin_family = AF_INET,
        .sin_port = htons(port_serv),
        .sin_addr.s_addr = INADDR_ANY

    };

    int error = bind(serv_fd, (struct sockaddr*) &serv, sizeof(serv)); perror("bind");
    if(error == -1) return EXIT_FAILURE;

    error = listen(serv_fd, BUFSIZ); perror("listen");
    if(error == -1) return EXIT_FAILURE;

    printf("\nÉcoute en cours sur le port %d\n", port_serv);

    return(serv_fd);
}