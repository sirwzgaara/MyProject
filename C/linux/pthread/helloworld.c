
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <pthread.h>
#include <signal.h>
#include <time.h>

pthread_t tid;
sigset_t set;

void myfunc()
{
    printf("hello\n");
}

static void *mythread(void *p)
{
    int signum;
    while (1)
    {
        sigwait(&set, &signum);
        if (SIGUSR1 == signum)
            myfunc();
        if (SIGUSR2 == signum)
        {
            printf("i will sleep 2 second and exit\n");
            sleep(2);
            break;
        }
    }
}

void main()
{
    char tmp;
    void *status;
    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);
    sigaddset(&set, SIGUSR2);
    sigprocmask(SIG_SETMASK, &set, NULL);
    pthread_create(&tid, NULL, mythread, NULL);

    while (1)
    {
        printf(":");
        scanf("%c", &tmp);
        if ('a' == tmp)
        {
            pthread_kill(tid, SIGUSR1);
        }
        else if ('q' == tmp)
        {
            pthread_kill(tid, SIGUSR2);
            pthread_join(tid, &status);
            printf("finish");
            break;
        }
        else
            continue;
    }
}
