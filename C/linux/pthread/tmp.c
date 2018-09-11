
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <pthread.h>
#include <signal.h>
#include <time.h>

void * func(void *p)
{
    while (1)
    {
        printf("1\n");
        sleep(1);
    }
}

void main()
{
    pid_t tpid;
    pthread_create(&tpid, NULL, func, NULL);
    pthread_join(tpid, NULL);
}
