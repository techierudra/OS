#include <stdio.h>
#include<unistd.h>
int main()
{
int pid,n,i,oddsum=0,evensum=0;
printf("Enter the value of n : ");
scanf("%d",&n);
pid=fork();
if(pid == 0){
for(i=0;i<=n;i++){
if(i%2==0){evensum+=i;}
else{oddsum+=i;}
}
}
printf("in parent");
printf("%d",evensum);
printf("%d",oddsum);
return 0;
}