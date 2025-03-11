#include "global.h"

int main(int argc, char** argv) 
{
    t_user client;
    
    int user_port = atoi(argv[1]);
    int port_serv = atoi(argv[2]);
    client.fd = initSocket(user_port, port_serv);
    char prenom [255]; strcpy(prenom, argv[3]);
    strcpy(client.name, prenom);

    printf("\n###################### TCHAT ###################\n");
    printf("- create salon : créer un salon de discussion publique\n");
    printf("- list users: Lister les utilisateurs connectés\n");
    printf("- list salons: Lister les salons de discution disponible\n");
    printf("- join salon *salon_id* : rejoindre un salon de discussion\n");
    printf("- join user *user_id* : rejoindre un joueur dans un salon privé\n");
    printf("- join world\n");
    printf("- exit : Se déconnecter ou revenir en arrière\n");
    printf("################################################\n\n");
    

    printf("Bienvenue %s\n", client.name);

    printf("Bienvenue %s\n\n", client.name);

    pthread_t send_thread;
    pthread_create(&send_thread, NULL, send_routine, &client);

    pthread_t rcv_thread;
    pthread_create(&rcv_thread, NULL, recv_routine, &client);

    










    while(1){}














    close(client.fd);

    return 0;
}