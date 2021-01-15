#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int numOfThreads = 4;
void* HelloWorld(void *threadid){
int id = (long) threadid;
printf("Hello, World! from thread id: %d\n", id);
pthread_exit((void *) 1);
}

int main(){
pthread_t threads; //there will be 4 separate threads besides main
int wasCreated;
long i;
for(i = 1; i <=  numOfThreads; i++){
//i will tell which thread we are on
 wasCreated = pthread_create(&threads, NULL, HelloWorld, (void *)i);
 if(wasCreated != 0){
 printf("Error: Wasn't able to create thread %d", i);
 return -1;
}
}
sleep(1);
pthread_exit(NULL);
}
