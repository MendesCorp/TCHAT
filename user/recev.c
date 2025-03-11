#pragma once 

#include "global.h"

void * recv_routine(void *arg)
{
    while(1)
    {
        
        t_user mailbox = *(t_user*)arg;
      
        int error = recv(mailbox.fd, &mailbox, sizeof(t_user), 0); perror("recv");
        if(error == -1) printf("erreur\n");

        // printf("début du thread RCV\n");
        // pthread_t recv_thread;
        // pthread_create(&recv_thread, NULL, recv_routine, &serv_fd);
        // printf("fin du thread RCV \n");
    }
}