#include "global.h"

int main () {

    int serv_fd = initSocket();

    struct sockaddr client;
    socklen_t len;
    int client_fd;

    int error = accept(serv_fd,(struct sockaddr*)&client, len);

    int users[BUF_SIZE];

   




















    close(serv_fd);

    return 0;
}