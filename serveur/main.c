#include "global.h"

// fonction pour le thread du salon publique

void public(void *) {
    while(1) {
        
    }


}


int main () {

    printf("\n###################### TCHAT ###################\n");
    printf("- create salon : créer un salon de discussion publique\n");
    printf("- list users: Lister les utilisateurs connectés\n");
    printf("- list salons: Lister les salons de discution disponible\n");
    printf("- join salon *salon_id* : rejoindre un salon de discussion\n");
    printf("- join user *user_id* : rejoindre un joueur dans un salon privé\n");
    printf("- join world\n");
    printf("- exit : Se déconnecter ou revenir en arrière\n");
    printf("################################################\n\n");

    serv_fd = initSocket();

    // init client
    struct sockaddr_in user;
    socklen_t len;
    
    // thread pour le salon publique = tout le monde peut recv et send 
    // pthread_t public_thread;
    
    // pthread_create(&public_thread,NULL, //fonction ,NULL);

    // pthread_join(public_thread, NULL);


    for(int i = 1; i < MAX_USERS; i++) {

        int user_fd = accept(serv_fd, (struct sockaddr*)&user, &len); perror("accept");
        if(user_fd == -1) return EXIT_FAILURE;

        char buf[255]; memset(buf, 0, 255);
        //identifiants_clients[i] = user_fd;
        int error = recv(user_fd, buf, sizeof(buf), 0); perror("recv");
        if(error == -1) return EXIT_FAILURE;

     
        printf("%s est connecté(e)\n", buf);
    

    
    //for (int i = 0; i < MAX_USERS; i++) {
    
   
    
    }




    close(serv_fd);















    return 0;
}