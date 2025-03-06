#pragma once
#include "global.h"

/*
mise en place du socket serveur, 
liaison et écoute sur le port choisi
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

/*
boucle pour obtenir les "recv" des clients en boucle
+ thread ? 
*/

void * traitement_rcv(void *arg)
{
    printf("recv_routine\n");
    
    int fd = *(int*) arg;   // transtypage void* arg en int

    t_delivery user;
    
   //int tableau fd clients = userfdstruct
    
    while(1) 
    {
        
        int nb_data_recved = recv(fd, &user, sizeof(t_delivery), 0); perror("rcv"); // *fd pour accéder à la valeur pointée
        printf("%s: %s \n",user.prenom,user.message);
        
        for(int i = 0; i < compteur_clients; i++) 
        {

            send(clients_fd[i], &user, sizeof(t_delivery), 0); perror("send");
            printf("%s: %s \n",user.prenom,user.message);
        }
        
        if(nb_data_recved == -1)
        {
            printf("erreur rcv//\n");
            continue;
        }
        
        
        //send(fd, &user,);
        
        // if(nb_data_recved == 0)     // pb à fix rcv à l'infini
        // {
        //     printf("utilisateur gone  :'(\n");
        //     nb_data_recved ++;
        //     continue;
        //     //s ici entrer le code en cas d'utilisateur parti
        //     // nb_users_quittants ++ ?
        // }
    }
    
}

/*
fonction "accept" pour pouvoir modifier le fd client, 

*/

void * accept_routine(void *arg)
{
    // "struct" client
    struct sockaddr_in user;
    socklen_t len;
    printf("accept_routine\n");

    pthread_t recv_thread;

    for(int i = 0; i < MAX_USERS; i++) 
    {
        
        int fd = accept(serv_fd, (struct sockaddr*)&user, &len); perror("accept");  // fd = valeur tampon
        clients_fd[i] = fd;
        printf("%d\n", clients_fd[i]);
        compteur_clients ++;
        pthread_create(&recv_thread, NULL, traitement_rcv, &clients_fd[i]);
    }    
    
    pthread_join(recv_thread,NULL);
}

/*
commentaire 
multiligne 
pour expliquer à quoi sert la fonction
*/

