#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main()
{
int shmid;
char *str;
shmid=shmget((key_t)6, 1024, IPC_CREAT |0666);
str=(char *)shmat(shmid, (char *)0,0);
printf("Enter data :");
fgets(str ,sizeof(str),stdin);
printf("Data successfully written into memory \n");
shmdt(str);
return 0;
}
// gcc ex9a.c
// ./a.out srmist