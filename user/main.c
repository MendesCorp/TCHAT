#include "global.h"

int main() {

    int user_fd = initSocket();

    char name[255]; memset(name, 0, 255);
    printf("Qui est connecté ?\n");
    fgets(name, 255, stdin);
    printf("./tchat connect %s\n", name);

    int error = send(user_fd, name, sizeof(name), 0); perror("send");
    if(error == -1) return EXIT_FAILURE;

    







    return 0;
}