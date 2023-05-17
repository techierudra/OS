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
    
    if ((key = ftok(".", 'a')) == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    if ((msgid = msgget(key, 0666)) == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    int message_number = atoi(argv[1]);

    if (msgrcv(msgid, &msg, sizeof(struct message), MESSAGE_TYPE, 0) == -1) {
        perror("msgrcv");
        exit(EXIT_FAILURE);
    }

    int received_message_number = atoi(strtok(msg.message_text, ":"));

    while (received_message_number != message_number) {
        if (msgrcv(msgid, &msg, sizeof(struct message), MESSAGE_TYPE, 0) == -1) {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }

        received_message_number = atoi(strtok(msg.message_text, ":"));
    }

    printf("Received message: %s\n", msg.message_text);

    return 0;
}
