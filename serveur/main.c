#include "global.h"

void * accept_routine(void *arg)
{
    // "struct" client
    struct sockaddr_in user;
    socklen_t len;
    printf("accept_routine");
    
    for(int i = 0; i < MAX_USERS; i++) {
        int fd = accept(serv_fd, (struct sockaddr*)&user, &len); perror("accept");
        if(fd != -1) user_fd[i] = fd; // vérifcation d'erreurs
        compteur_clients ++;
    }    
}

void * recv_routine(void *arg)
{
    char buf[255];

    for(int i = 0; i < compteur_clients; i++) 
    {
        printf("recv_routine");
        int nb_data_recved = recv(user_fd[i], buf, sizeof(buf), 0); perror("rcv");

        if(nb_data_recved == -1)
        {
            printf("erreur incongrue \n");
            continue;
        }
        
        if(nb_data_recved == 0)
        {
            printf("utilisateur gone  :'(\n");continue;
        /// ici entrer le code en cas d'utilisateur parti
        // nb_users_quittants ++ ?
        }

        printf("test :%s\n", buf);

        if(compteur_clients == i) i = 0;
        
    }
}

int main () 
{
    
    serv_fd = initSocket();
    
    pthread_t accept_thread;
    pthread_create(&accept_thread, NULL, accept_routine, NULL);
    pthread_join(accept_thread,NULL);
    
    char buf[255]; memset(buf, 0, 255);
    pthread_t recv_thread;
    pthread_create(&recv_thread, NULL, recv_routine, NULL);
    pthread_join(recv_thread,NULL);
    
    
    close(serv_fd);
    return 0;
}