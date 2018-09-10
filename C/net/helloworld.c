
#include <stdio.h>
#include <hiredis/hiredis.h>

void main()
{
    redisContext * conn = redisConnect("10.1.108.51", 6379);
    if (conn->err)
    {
        printf("connect error\n");
        redisFree(conn);
        return;
    }

    while (1);
}
