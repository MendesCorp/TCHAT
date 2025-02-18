#include "global.h"

void * send_routine(void *arg)
{
   // int* user_fd = (int*)arg;
    for(int i = 1; i < MAX_USERS; i++) {

        char buf[255];
        fgets(buf,sizeof(buf),stdin);
        int error = send(user_fd, buf, sizeof(buf), 0); perror("send");
        if (error != -1); return EXIT_SUCCESS;
    }
}

int main() 
{

    user_fd = initSocket();

    printf("\n###################### TCHAT ###################\n");
    printf("- create salon : créer un salon de discussion publique\n");
    printf("- list users: Lister les utilisateurs connectés\n");
    printf("- list salons: Lister les salons de discution disponible\n");
    printf("- join salon *salon_id* : rejoindre un salon de discussion\n");
    printf("- join user *user_id* : rejoindre un joueur dans un salon privé\n");
    printf("- join world\n");
    printf("- exit : Se déconnecter ou revenir en arrière\n");
    printf("################################################\n\n");

    char name[255]; memset(name, 0, 255);
    printf("Qui est connecté ?\n");
    fgets(name, 255, stdin);
    printf("./tchat connect %s\n", name);
    
    pthread_t send_thread;
    pthread_create(&send_thread, NULL, send_routine, &serv_fd);
    

    while(1){}














    close(user_fd);

    return 0;
}