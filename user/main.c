#include "global.h"

int main(int argc, char** argv) 
{
    t_delivery user;
    
    user.user_fd = initSocket();

    char prenom [255]; strcpy(prenom, argv[1]);
    strcpy(user.prenom, prenom);

    printf("\n###################### TCHAT ###################\n");
    printf("- create salon : créer un salon de discussion publique\n");
    printf("- list users: Lister les utilisateurs connectés\n");
    printf("- list salons: Lister les salons de discution disponible\n");
    printf("- join salon *salon_id* : rejoindre un salon de discussion\n");
    printf("- join user *user_id* : rejoindre un joueur dans un salon privé\n");
    printf("- join world\n");
    printf("- exit : Se déconnecter ou revenir en arrière\n");
    printf("################################################\n\n");
    
    printf("Bienvenue %s\n", user.prenom);
    pthread_t send_thread;
    pthread_create(&send_thread, NULL, send_routine, &user);

    

    while(1){}














    close(user.user_fd);

    return 0;
}