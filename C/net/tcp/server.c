
#ifdef _cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>


#define MYPORT 8887
#define QUEUE 20
#define BUFFER_SIZE 1024

void main()
{
    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_sockaddr;
    server_sockaddr.sin_family 		= AF_INET;
    server_sockaddr.sin_port 		= htons(MYPORT);
    server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_sockfd, (struct sockaddr *)&server_sockaddr, sizeof(server_sockaddr)) == -1)
    {
        printf("bind error\n");
        return;
    }

    printf("start list to port %d", MYPORT);

    if (listen(server_sockfd, QUEUE) == -1)
    {
        printf("listen error\n");
        return;
    }

    char buffer[BUFFER_SIZE];
    struct sockaddr_in client_addr;
    socklen_t length = sizeof(client_addr);

    printf("等待客户端连接\n");
    int conn = accept(server_sockfd, (struct sockaddr*)&client_addr, &length);
    if (conn < 0)
    {
        printf("accept error\n");
        return;
    }

    printf("客户端成功连接\n");

    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        int len = recv(conn, buffer, sizeof(buffer), 0);
        if (strcmp(buffer, "exit\n") == 0 || len <= 0)
            break;
        printf("来自客户端数据：%s\n", buffer);
        send(conn, buffer, len, 0);
        printf("发送给客户端数据：%s\n", buffer);
    }
    close(conn);
    close(server_sockfd);

	return;
}

#ifdef _cplusplus
}
#endif

