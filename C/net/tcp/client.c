
#ifdef _cplusplus
extern "C" {
#endif


#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

//#define MYPORT 8887
#define MYPORT 600
#define BUFFER_SIZE 1024
char * SERVER_IP = "10.1.108.51";

void main()
{
	char sendbuf[BUFFER_SIZE];
	char recvbuf[BUFFER_SIZE];

	int sock_cli = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family 	 = AF_INET;
	servaddr.sin_port 		 = htons(MYPORT);
	servaddr.sin_addr.s_addr = inet_addr(SERVER_IP);

	printf("start connection\n");

	if (connect(sock_cli, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
	{
		printf("connect error%s\n", strerror(errno));
		return;
	}
    printf("connect error%s\n", strerror(errno));
	printf("connection done\n");
	
	while (fgets(sendbuf, sizeof(sendbuf), stdin) != NULL)
	{
		printf("start send message %s\n", sendbuf);
		send(sock_cli, sendbuf, strlen(sendbuf), 0);
		if (strcmp(sendbuf, "exit\n") == 0)
		{
			break;
		}
		recv(sock_cli, recvbuf, sizeof(recvbuf), 0);
		printf("get buf from server %s\n", recvbuf);

		memset(sendbuf, 0, sizeof(sendbuf));
		memset(recvbuf, 0, sizeof(recvbuf));
	}
	close(sock_cli);
	return;
}





#ifdef _cplusplus
}
#endif
