#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *thread(void *arg)
{
 	pthread_detach(pthread_self());
	sleep(2);
 	printf("\nIn Thread...!\n");
	for(int i=1;i<=10;i++)
		printf("\n Val:: %d",i);
 	//pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
 	pthread_t t;
 	int ret = pthread_create(&t, NULL, thread, NULL);
	
 	if (ret != 0) {
 	 	printf("Thread Creation Error\n");
 	 	exit(1);
 	}
 	printf("Thread created in Main\n");
	printf("\n In main...");
	
 	pthread_exit(NULL);
	printf("\n After exit main...");
	
}






