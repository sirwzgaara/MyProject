
#ifdef _cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <hiredis/hiredis.h>


void main()
{
	redisContext * conn = redisConnect("127.0.0.1", 6379);
	if (conn->err)
    {
        printf("connection error\n");
        redisFree(conn);
        return;
    }

	redisReply * reply = redisCommand(conn, "set foo 1234");
	freeReplyObject(reply);

	reply = redisCommand(conn, "get foo");
    if (reply && reply->str)
    {
        printf("%s\n", reply->str);
    }
    else
    {
        printf("not found\n");
    }

	freeReplyObject(reply);

	redisFree(conn);
}



#ifdef _cplusplus
}
#endif

