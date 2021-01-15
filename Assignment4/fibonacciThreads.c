#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

int sum = 0;
int *arr;

void *Fibonnaci(void *size) {
	int length = (int)size;
	int first = 0;
	int second = 1;
	int result;
	int counter = 0;
	int list[length];

	if (length == 1) {
		list[counter] = first;
	}

	if (length == 2) {
		list[0] = first;
		list[1] = second;
	}

	if (length > 2) {
		list[0] = first;
		list[1] = second;
		counter = 2;
		int i;

		for (i = 2; i < length; i++) {
			result = first + second;
			list[counter] = result;
			first = second;
			second = result;
			counter++;
		}
	}

	int i;
	for (i = 0; i < length; i++) {
		arr[i] = list[i];
	}
	pthread_exit((void*)0);
}

void* Runner(void *size) {

	int counter = 0;
	int length = (int)size;

	int j;
	for (j = 0; j < length; j++) {
		sum = sum + arr[counter];
		counter++;
	}

	pthread_exit((void*)0);
}

int main() {
	pthread_t thread1, thread2;
	int numberOfMembers = 0;
	bool unevenMembers = true;

	printf("Hello! Welcome to a program that gives you both the fibonacci sequence and the sum of that sequence\n");

	while (unevenMembers) {
		printf("First type in a positive length: ");
		scanf("%d", &numberOfMembers);
		printf("\n");
		if (numberOfMembers < 0) {
			printf("You haven't entered a positive number \n");
		}
		else if (numberOfMembers > 0) {
			unevenMembers = false;
		}
	}

	printf("You have %d integers\n", numberOfMembers);

	arr = malloc(numberOfMembers * sizeof(int));

	int check;
	//now we are going to do the threads
	printf("Thread 1 Starting \n");
	check = pthread_create(&thread1, NULL, Fibonnaci, (void*)numberOfMembers);
	if (check != 0) {
		printf("Error the threads didn't work");
		return 0;
	}

	check = pthread_join(thread1, NULL);
	if (check != 0) {
		printf("Error thread didn't join");
		return 0;
	}
	printf("Thread 1 Ending \n");

	printf("The sequence is ");

	int i;

	for (i = 0; i < numberOfMembers; i++) {
		printf("%d, ", arr[i]);
	}
	printf("\n");

	printf("Thread 2 Starting\n");
	check = pthread_create(&thread2, NULL, Runner, (void*)numberOfMembers);
	if (check != 0) {
		printf("Error thread did not create");
	}

	check = pthread_join(thread2, NULL);
	if (check != 0) {
		printf("Error thread did not join");
	}
	printf("Thread 2 Ending\n");

	printf("The sum of this sequence is %d\n", sum);

	pthread_exit(NULL);

	return 0;
}

