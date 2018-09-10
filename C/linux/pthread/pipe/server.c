
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>


void main()
{
    int fd[2];
    char buf[100] = {0};
    int n;

    printf("before open\n");

    /* 打开读管道 */
    fd[0] = open("/tmp/server_read", O_NONBLOCK | O_RDONLY);
    if (fd[0] < 0)
    {
        printf("server open fd[0] failed\n");
        return;
    }

    printf("after open\n");

    /* 循环从读管道中读取数据 */
    while (1)
    {
        n = read(fd[0], buf, 100);
        if (n == 0)
        {
            printf("no data, sleep 1s\n");
            sleep(1);
        }
        else if (n == -1)
        {
            printf("n is -1, sleep(1)\n");
            sleep(1);
        }
        /* 若读取到了数据，打开写管道，回复客户端 */
        else
        {
            printf("data from client, %s\n", buf);

            /* 写通道需要阻塞获取，因为可能没有读端在监听 */
            fd[1] = open("/tmp/server_write", O_WRONLY);
            if (fd[1] < 0)
            {
                printf("server open fd[1] failed\n");
                close(fd[0]);
                return;
            }

            /* 打开后说明有人读了，写入数据 */
            n = write(fd[1], "llllll", 6);
            if (n < 0)
            {
                printf("server write failed\n");
            }
            sleep(1);
        }
    }
    close(fd[0]);
    close(fd[1]);
}
