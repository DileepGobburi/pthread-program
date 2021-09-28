
#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // sleep

void* my_thread(void *ptr)
{    
     printf("\n Entered in pthread");
     printf("\n pthread ID    :: %lu\n",pthread_self());
     sleep(2);
     printf("\n Thread stop");

}

int main()
{
    pthread_t t;
    int ret;

    ret = pthread_create(&t,NULL,my_thread,NULL);
    if (ret !=0) 
    {
            printf("ERORR; return code from pthread_create() is %d\n", ret);
            return -1;
    }
    
    //int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine) (void *), void *arg);
    
    pthread_join(t,0);  //int pthread_join(pthread_t thread, void **retval);

    printf("\n\n Main function...");
    printf("\n PID:: %d\n", getpid());
    
    return 0;
}

