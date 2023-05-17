#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_MESSAGE_SIZE 100
#define MESSAGE_TYPE 1

struct message {
    long message_type;
    char message_text[MAX_MESSAGE_SIZE];
};

int main(int argc, char *argv[]) {
    key_t key;
    int msgid;
    struct message msg;
    int message_number = 1;

    if ((key = ftok(".", 'a')) == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    if ((msgid = msgget(key, 0666 | IPC_CREAT)) == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        msg.message_type = MESSAGE_TYPE;
        sprintf(msg.message_text, "Message %d: %s", message_number, argv[i]);

        if (msgsnd(msgid, &msg, strlen(msg.message_text) + 1, 0) == -1) {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }

        message_number++;
    }

    printf("Messages sent to the message queue.\n");

    return 0;
}
