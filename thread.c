//pthread program with two threads creation and join and exit functions
#include<stdio.h>
#include<pthread.h>
void* thread1(void* p)
{
	printf("%s\n",(char*)p);
	for(int i=0;i<=25;i++)
	printf("%c ",65+i);
	sleep(10);
	printf("thread1 terminated\n");
	pthread_exit("bye bye thread1\n");//terminating the calling thread(removing the all the resoureces allocated the thread)
}
void* thread2(void* p)
{
	printf("%s\n",(char*)p);
	sleep(20);
	printf("thread2 terminated\n");
}
int main()
{
pthread_t t1,t2;
void *p;
pthread_create(&t1,0,thread1,"hello thread1");
pthread_create(&t2,0,thread2,"hello threadd2");
printf("witing for thread1 termination\n");
pthread_join(t1,&p);//wait for particular thread termination
printf("after thread join function\n");
printf("%s\n",(char*)p);
while(1);

}
