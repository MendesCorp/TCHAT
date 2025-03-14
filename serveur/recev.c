#pragma once

#include "global.h"

/*
recv en boucle
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
                printf("user gone  :'(\n");
                nb_datas ++;
                continue;
            //     // nb_users_quittants ++ ?
            }
        }
    }
}