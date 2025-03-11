#pragma once

#include "global.h"

/*
fonction "accept" pour pouvoir modifier le fd client

*/

void * accept_routine(void *arg)
{
    // "struct" client

    struct sockaddr_in client;
    socklen_t len;
    printf("ACCEPT ✅\n");

    pthread_t recv_thread;


    t_user utilisateur;

    for(int i = 0; i < MAX_USERS; i++) 
    {      
        utilisateur.fd = accept(serv_fd, (struct sockaddr*)&client, &len); perror("accept");  // fd = valeur tampon

        // users[i].fd = fd;
        // users_fd[i]=fd;
        

        //users[i].room = 0; /// 0 == world

        compteur_clients ++;
        pthread_create(&recv_thread, NULL, traitement_rcv, &users[i]);
    }    
    
    pthread_join(recv_thread,NULL);
}