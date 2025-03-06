#include "global.h"

int main (int argc, char** argv) 
{
    
    int port_serv = atoi(argv[1]);

    serv_fd = initSocket(port_serv);
    pthread_t accept_thread;
    pthread_create(&accept_thread, NULL, accept_routine, NULL);
    pthread_join(accept_thread,NULL);
    
    char buf[255]; memset(buf, 0, 255);


    close(serv_fd);

    return 0;
}