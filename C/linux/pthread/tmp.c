
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>


void main()
{
    int fd;
    fd = open("/tmp/myfifo", O_NONBLOCK | O_RDONLY);
    printf("open ok\n");
    while (1);
}
