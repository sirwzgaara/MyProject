
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>

void main()
{
    int fd;
    fd = open("/tmp/myfifo", O_WRONLY);
    if (fd < 0)
    {
        printf("failed\n");
        return;
    }
    printf("open ok\n");
    close(fd);
}
