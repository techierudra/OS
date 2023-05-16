// First create f1 with some contents (cat>f1)
// Hi hello ashok
// How r u
// Good morning
#include <stdio.h>
#include<unistd.h>
int main()
{
printf("Transfer to execlp function \n");
execlp("head", "head","-2","f1",NULL);
printf("This line will not execute \n");
return 0;
}
// output
// Transfer to execlp function
// Hi hello ashok
// How r u