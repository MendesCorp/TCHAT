#include "global.h"


void * recv_routine(void *arg)
{
    printf("recv_routine\n");
    char buf[255];
    
    int* fd = (int*) arg;   // transtypage void* arg en int
    
    while(1) 
    {
        
        int nb_data_recved = recv(*fd, buf, sizeof(buf), 0); perror("rcv"); // *fd pour accéder à la valeur pointée
        
        if(nb_data_recved == -1)
        {
            printf("erreur incongrue \n");
            continue;
        }
        
        if(nb_data_recved == 0)
        {
            printf("utilisateur gone  :'(\n");continue;
            //s ici entrer le code en cas d'utilisateur parti
            // nb_users_quittants ++ ?
        }
        
        printf("test :%s\n", buf);
    }
}

void * accept_routine(void *arg)
{
    // "struct" client
    struct sockaddr_in user;
    socklen_t len;
    printf("accept_routine\n");

    for(int i = 0; i < MAX_USERS; i++) {

        int fd = accept(serv_fd, (struct sockaddr*)&user, &len); perror("accept");  // fd = valeur tampon
        if(fd != -1) user_fd[i] = fd; // vérifcation d'erreurs
        compteur_clients ++;
        pthread_t recv_thread;
        pthread_create(&recv_thread, NULL, recv_routine, &user_fd[i]);
        pthread_join(recv_thread,NULL);
    }    
}

int main () 
{
    
    serv_fd = initSocket();
    
    pthread_t accept_thread;
    pthread_create(&accept_thread, NULL, accept_routine, NULL);
    pthread_join(accept_thread,NULL);
    
    char buf[255]; memset(buf, 0, 255);

    close(serv_fd);

    return 0;
}