#include "global.h"
int lastUserIndex = 0;

void* accept_loop_thread(void* arg) {

    while(1) { 
        struct sockaddr user;
        socklen_t len;
        int user_fd = accept(serv_fd,(struct sockaddr*)&user, &len); perror("accept");
        if(user_fd == -1) return EXIT_FAILURE;
        users[lastUserIndex] = user_fd;
        lastUserIndex++;
    }
}

void* recv_thread(void* arg){
    
    
    
    return NULL;
}

int main () {
    
    serv_fd = initSocket();
    
    
    pthread_t accept_thread;
    pthread_create(&accept_thread,NULL,accept_loop_thread,NULL);
    
    // sleep(10);
    for (int i = 0; i < lastUserIndex; i++)
    {
        /* code */
        char buf[255]; memset(buf, 0, 255);
        int error = recv(users[i], buf, sizeof(buf), 0); perror("recv");
        if(error == -1) return EXIT_FAILURE;
    }
    

    printf("%s\n", buf);
   
    





    close(serv_fd);

    return 0;
}