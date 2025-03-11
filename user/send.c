#pragma once 

#include "glob.h"

void * send_routine(void *arg)
{

   t_user client = *(t_user*)arg;
   // int* user_fd= (int*)arg;
   t_message colis; 

   char buf[255]; 
   
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
        
        memset(buf, 0, 255);
    }
    printf("%s : %s\n", client.name, colis.message);
}