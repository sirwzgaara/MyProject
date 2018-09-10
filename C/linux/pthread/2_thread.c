
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>

void main()
{
    int fd;
    char buf[100] = {0};
    int n = 0;

    /* 若访问失败，可能管道被删除了，尝试重新创建管道 */
    if (access("/tmp/myfifo", F_OK) != 0)
    {
        if (mkfifo("tmp/myfifo", 0777) < 0)
        {
            printf("create fifo failed\n");
            return;
        }
    }

    /* 打开写管道 */
    printf("before open\n");
    fd = open("/tmp/myfifo", O_NONBLOCK | O_WRONLY);
    if (fd < 0)
    {
        printf("open error\n");
        return;
    }
    printf("after open\n");

    /* 这段注释掉的是server处理机制 */
#if 0
    while (1)
    {
        memset(buf, 0, sizeof(buf));
        if ((n = read(fd, buf, 100)) == 0)
        {
            printf("n = %d\n", n);
            printf("no data in fifo\n");
            sleep(1);
        }
        else
        {
            printf("n = %d\n", n);
            printf("get data: %s\n", buf);
            sleep(1);
        }
    }
#endif

    /* 向写管道写入数据 */
    n = write(fd, "abc123", 6);
    if (n < 0)
    {
        printf("write failed\n");
    }
    close(fd);
}
