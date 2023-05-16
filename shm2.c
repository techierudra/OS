#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main()
{
int shmid;
char *str;
shmid = shmget((key_t)6, 1024, IPC_CREAT | 0666);
str = (char *)shmat(shmid, (char *)0, 0);
printf("Data read from memory : %s \n", str);
shmdt(str);
shmctl(shmid, IPC_RMID, NULL);
return 0;
}
// gcc ex9b.c
// ./a.out