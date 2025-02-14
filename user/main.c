#include "global.h"

int main() {

    int user_fd = initSocket();

    char first_sms[255]; memset(first_sms, 0, 255);
    printf("test 1er envoi au serveur\n");
    fgets(first_sms, 255, stdin);

    int error = send(user_fd, first_sms, sizeof(first_sms), 0); perror("send");
    if(error == -1) return EXIT_FAILURE;

    







    return 0;
}