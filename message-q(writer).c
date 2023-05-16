#include<stdio.h> //writer to message queue
#include<string.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
int main(int argc,char *argv[]){
int len,mid,i=1;
struct buffer {
long mtype;
char buf[50];
} x;
mid=msgget((key_t)6,IPC_CREAT|0666);
x.mtype=atol(argv[1]); //message type number
strcpy(x.buf,argv[2]); // message text
len=strlen(x.buf);
msgsnd(mid,&x,len,0);
printf("message of size %d sent successfully \n",len);
return 0;
}
// $ ipcs -q
// gedit ex8a.c
// gcc ex8a.c
// /.a.out 1 welcome
// /.a.out 2 hello
// /.a.out 3 srmist
// $ ipcs -q