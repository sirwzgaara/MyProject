
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>

void main()
{
    /* 管道文件只创建一次就行了，以后只要使用和维护 */
#if 0
    int fd;
    if (mkfifo("/tmp/myfifo", 0777) < 0)
    {
        printf("create failed\n");
        return;                      
    }
#endif
    int fd;
    char buf[100] = {0};
    int n = 0;

    /* 打开读管道 */
    printf("before open\n");

    /* 只读，非阻塞 */
    fd = open("/tmp/myfifo", O_NONBLOCK |  O_RDONLY);
    if (fd < 0)
    {
        return;
    }

    printf("after open\n");

    /* 死循环从读管道中读取数据 */
    while (1)
    {
        /* 注意每次循环都要清理buf */
        memset(buf, 0, sizeof(buf));
        if ((n = read(fd, buf, 100)) == 0)
        {
            printf("not read data from client: n = %d\n", n);
            printf("no data in fifo\n");
            sleep(1);
        }
        /* 若读取到了，使用写管道写回客户端 */
        else
        {
            printf("read data from client: n = %d\n", n);
            printf("get data: %s\n", buf);
            printf("error %s\n", strerror(errno));
            sleep(1);
        }
    }
    close(fd);
}
