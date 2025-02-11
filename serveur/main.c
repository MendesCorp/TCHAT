#include "global.h"

int main () {

    int serv_fd = initSocket();

    struct sockaddr user;
    socklen_t len;

    int user_fd = accept(serv_fd,(struct sockaddr*)&user, &len); perror("accept");
    if(user_fd == -1) return EXIT_FAILURE;

    int users[BUF_SIZE];

    char buf[255]; memset(buf, 0, 255);

    int error = recv(user_fd, buf, sizeof(buf), 0); perror("recv");
    if(error == -1) return EXIT_FAILURE;

    printf("%s\n", buf);
   




















    close(serv_fd);

    return 0;
}