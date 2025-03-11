#pragma once
#include "global.h"

int initSocket(int user_port, int serv_port) 
{
    int user_fd = socket(AF_INET, SOCK_STREAM, 0); perror("socket");
    if(user_fd == -1) return EXIT_FAILURE;
    
    struct sockaddr_in user = {
        .sin_family = AF_INET,
        .sin_port = htons(user_port),
        .sin_addr.s_addr = INADDR_ANY

    };
    
    int error = bind(user_fd, (struct sockaddr*) &user, sizeof(user)); perror("bind");
    if(error == -1) return EXIT_FAILURE; 
    
    struct sockaddr_in serv = {
        .sin_family = AF_INET,
        .sin_port = htons(serv_port),
        .sin_addr.s_addr = inet_addr("127.0.0.1")
    };
    
    error = connect(user_fd, (struct sockaddr*) &serv, sizeof(serv)); perror("connect");
    if(error == -1) return EXIT_FAILURE;

    return(user_fd);
}


void * send_routine(void *arg)
{

   t_user client = *(t_user*)arg;
   // int* user_fd= (int*)arg;
   t_message colis; 
   colis.name == client.name;
   printf("%s : %s\n", colis.name, colis.message);
   
    
    char buf[255]; memset(buf, 0, 255);

    while(1) {

        fgets(buf,sizeof(buf),stdin);
        buf[strlen(buf)-1] = 0;     // rm \n
        
        strcpy(colis.message, buf);
        
        /*
        envoi du colis à la bonne adresse avec la bonne taille de struct 
        */
        int error = send(client.fd, &colis, sizeof(t_message), 0); perror("send");
        //printf("%s: %s \n",colis.name, colis.message);
        if (error == -1) printf("erreur\n"); 
    }
}

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