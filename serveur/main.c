#include "global.h"

void * accept_routine(void *arg){
    // init client
    struct sockaddr_in user;
    socklen_t len;

    for(int i = 1; i < MAX_USERS; i++) {
        user_fd = accept(serv_fd, (struct sockaddr*)&user, &len); perror("accept");
    }    
}

int main () {

    serv_fd = initSocket();

    pthread_t accept_thread;
    pthread_create(&accept_thread, NULL, accept_routine, NULL);

    sleep(10);

    char buf[255]; memset(buf, 0, 255);
    
    int error = recv(user_fd, buf, sizeof(buf), 0); perror("recv");
    if(error == -1) return EXIT_FAILURE;
    
    buf[strlen(buf)-1]= 0;
    
    printf("%s est connecté(e)\n", buf);
    

    
    close(serv_fd);















    return 0;
}