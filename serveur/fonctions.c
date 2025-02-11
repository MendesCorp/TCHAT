#include "global.h"

int initSocket(int serv_fd) {

    serv_fd = socket(AF_INET, SOCK_STREAM, 0); perror("socket");
    if(serv_fd == -1) return EXIT_FAILURE;

    struct sockaddr_in serv = {
        .sin_family = AF_INET,
        .sin_port = htons(SERV_PORT),
        .sin_addr.s_addr = INADDR_ANY

    };

    int error = bind(serv_fd, (struct sockaddr*) &serv, sizeof(serv)); perror("bind");
    if(error == -1) return EXIT_FAILURE; 

    error = listen(serv_fd, BUFSIZ); perror("listen");
    if(error == -1) return EXIT_FAILURE;

    printf("Ecoute en cours sur le port %d\n", SERV_PORT);

    return(serv_fd);
}