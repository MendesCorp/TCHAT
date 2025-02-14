#include "global.h"


void* accept_loop_thread(void* arg) {

//     while(1) { 
//         struct sockaddr user;
//         socklen_t len;
//         int user_fd = accept(serv_fd,(struct sockaddr*)&user, &len); perror("accept");
//         if(user_fd == -1) return EXIT_FAILURE;
//         // users[users] = user_fd;
//         // user++;
//     }
// }

void* recv_thread(void* arg){
    
    
    
    return NULL;
}

int main () {
    
    serv_fd = initSocket();
    
    pthread_t accept_thread;

    pthread_create(&accept_thread,NULL,accept_loop_thread,NULL);
    
    char buf[255]; memset(buf, 0, 255);
    
    for (int i = 0; i < users; i++) {}
    
        int error = recv(users[i], buf, sizeof(buf), 0); perror("recv");
        if(error == -1) return EXIT_FAILURE;
    }
    
    printf("%s\n", buf);
   
    





    close(serv_fd);

    return 0;
}