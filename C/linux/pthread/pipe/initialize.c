
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>

void main()
{
    if (access("/tmp/myfifo", F_OK) != 0)
    {
        if (mkfifo("/tmp/myfifo", 0777) < 0)
        {
            printf("create /tmp/myfifo failed\n");
            return;                                                     
        }               
    }

    if (access("/tmp/server_write", F_OK) != 0)
    {
        if (mkfifo("/tmp/server_write", 0777) < 0)
        {
            printf("create /tmp/server_write failed\n");
            return;                
        }
    }

    if (access("/tmp/server_read", F_OK) != 0)
    {
        if (mkfifo("/tmp/server_read", 0777) < 0)
        {
            printf("create /tmp/server_read failed\n");
            return;
        }
    }

    printf("create all FIFO success\n");
}
