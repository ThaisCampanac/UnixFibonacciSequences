#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>

void err_sys(const char *type){
printf(type);
exit(EXIT_FAILURE);
}

int main(){
pid_t parent = getpid();
pid_t child;
pid_t pid;
int returnStatus;

if((pid=fork())<0){
err_sys("Fork Failure");
}

else if(pid == 0){
child = getpid();
printf("The pids of the child and parent process are: %d and %d.\n",child,parent);

int numberOfMembers;
bool unevenMembers = true;

//write the fibbinoci code here
while(unevenMembers){
printf("Enter an even number of members for the Fibonacci sequence: ");
scanf("%d", &numberOfMembers);
printf("\n");
if(numberOfMembers <  0){
printf("You haven't entered a postive amount \n");
}
else if(numberOfMembers > 0){
unevenMembers = false;
}
}

//the series is printed here
int first = 0;
int second = 1;
int result;
if(numberOfMembers == 1){
printf("The Fibonacci sequence is %d\n",first);
}
if(numberOfMembers == 2){
printf("The Fibonacci sequence is %d, %d\n",first,second);
}
else if(numberOfMembers > 2){
int counter = 0;
printf("The Fibonacci sequence is %d, %d, ",first,second);
numberOfMembers = numberOfMembers -2;
for(counter; counter <numberOfMembers; counter++){
result = first + second;
printf("%d, ", result);
first = second;
second = result;
}
printf("\n");
}
}

else{
waitpid(pid, &returnStatus, 0);
printf("The Parent has waited for the child");
}

return 0;
}
