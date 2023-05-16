#include <stdio.h> // reader to message queue
#include<string.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
int main(int arg, char *argv[])
{
int len, mid, i = 1;
struct buffer
{
long mtype;
char buf[50];
} x;
mid = msgget((key_t)6, 0666);
x.mtype = atoi(argv[1]); //message type number
len = atoi(argv[2]); //length of the message
msgrcv(mid, &x, len,x.mtype, 0);
printf("The message is : %s\n",x.buf);
return 0;
}
// gedit ex8b.c
// gcc ex8b.c
// a.out 2 10
// $ ipcs -q