#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
void err_sys(const char *type){
printf(type);
exit(EXIT_FAILURE);
}

int main(){
pid_t parent = getpid();
pid_t child;
pid_t pid;

pid = fork();

if(pid < 0){
printf("We have failed the fork");
err_sys("fork failed");
}

else if(pid == 0){
printf("Hello World!\n");
child = getpid();
printf("The child process and parent process ids are: %d and %d.\n ",child,parent);
}
return 0;
}
