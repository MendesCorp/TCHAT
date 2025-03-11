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
    printf("RECV ✅\n");
    
    t_user client = *((t_user*) arg);   // transtypage void* arg en int
    t_message colis;
    
    while(1) 
    {

        for(int i = 0; i < compteur_clients; i++) 
        {
            int nb_datas = recv(client.fd, &colis, sizeof(t_message), 0); perror("rcv"); // *fd pour accéder à la valeur pointée
            printf("%s: %s \n", colis.name, colis.message);

            // printf("SEND ✅\n");
            // send(users_fd[i], &colis, sizeof(t_message), 0); perror("send");
            // printf("%s: %s \n", colis.name, colis.message);
    
    
            if(nb_datas == -1)
            {
                printf("erreur rcv//\n");
                continue;
            }
            
            // //(user.id_room == idroom receptionneur)
                

            if(nb_datas == 0)     // !!!!! pb à fix rcv à l'infini
            {
                printf("utilisateur gone  :'(\n");
                nb_datas ++;
                continue;
            //     // nb_users_quittants ++ ?
            }
        }
    }
    
}

/*
fonction "accept" pour pouvoir modifier le fd client

*/

void * accept_routine(void *arg)
{
    // "struct" client
    struct sockaddr_in user;
    socklen_t len;
    printf("ACCEPT ✅\n");

    pthread_t recv_thread;

    for(int i = 0; i < MAX_USERS; i++) 
    {
        t_user user_infos;
        
        int fd = accept(serv_fd, (struct sockaddr*)&user, &len); perror("accept");  // fd = valeur tampon
        users[i].fd = fd;
        users_fd[i]=fd;
        //users[i].room = 0; /// 0 == world

        compteur_clients ++;
        pthread_create(&recv_thread, NULL, traitement_rcv, &users[i]);
    }    
    
    pthread_join(recv_thread,NULL);
}

/*
commentaire 
multiligne 
pour expliquer à quoi sert la fonction
*/

