#pragma once
#include "global.h"

int initSocket() 
{

    int user_fd = socket(AF_INET, SOCK_STREAM, 0); perror("socket");
    if(user_fd == -1) return EXIT_FAILURE;
    
    struct sockaddr_in user = {
        .sin_family = AF_INET,
        .sin_port = htons(USER_PORT),
        .sin_addr.s_addr = INADDR_ANY

    };
    
    int error = bind(user_fd, (struct sockaddr*) &user, sizeof(user)); perror("bind");
    if(error == -1) return EXIT_FAILURE; 
    
    struct sockaddr_in serv = {
        .sin_family = AF_INET,
        .sin_port = htons(SERV_PORT),
        .sin_addr.s_addr = inet_addr("127.0.0.1")
    };
    
    error = connect(user_fd, (struct sockaddr*) &serv, sizeof(serv)); perror("connect");
    if(error == -1) return EXIT_FAILURE;

    return(user_fd);
}