#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
int pipes[2];
char buff[25];
pipe(pipes);
if (fork() == 0) {
printf("Child: Writing to pipe\n");
write(pipes[1], "Hello World!", 13);
printf("Child Exiting\n");
} else {
wait(NULL);
printf("Parent: Reading from pipe\n");
read(pipes[0], buff, 13);
printf("Pipe content is: %s\n", buff);
}
return 0;
}