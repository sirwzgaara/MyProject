
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
    
    /* 打开写管道，这里阻塞，否则若没有读端打开，open会返回失败 */
    fd[1] = open("/tmp/server_read", O_WRONLY);
    if (fd[1] < 0)
    {
        printf("client open fd[1] failed\n");
        return;
    }

    /* 写入数据 */
    n = write(fd[1], "abc123", 6);
    if (n < 0)
    {
        printf("client write failed\n");
        return;
    }

    /* 打开读通道 */
    fd[0] = open("/tmp/server_write", O_RDONLY);
    if (fd[0] < 0)
    {
        printf("server open fd[0] failed\n");
        close(fd[1]);
        return;
    }

    /* 从读通道读取数据 */
    while (1)
    {
        if (read(fd[0], buf, 100))
        {
            printf("data from server is %s\n", buf);
            break;
        }
        sleep(1);
    }
    memset(buf, 0, 100);
    close(fd[0]);
    close(fd[1]);
}
