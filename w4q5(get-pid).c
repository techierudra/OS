#include<stdio.h>
#include<unistd.h>
int main(){
int pid = fork();
if(pid==0){
printf(" in child %d %d",getpid(),getppid());
}
else{
sleep(1);
printf(" in parent %d %d",getpid(),getppid());
}
return 0;
}