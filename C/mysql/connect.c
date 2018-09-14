
#include <stdio.h>
#include <mysql/mysql.h>

void main()
{
    MYSQL mysql;
    if (NULL == mysql_init(&mysql))
    {
        printf("mysql_init() : %s\n", mysql_error(&mysql));
        return;
    }

    if (NULL == mysql_real_connect(&mysql, "localhost", "root",
                    "123456", "wz", 0, NULL, 0))
    {
        printf("mysql_real_connect() : %s\n", mysql_error(&mysql));
        return;
    }
    printf("connect mysql successful\n");

    mysql_close(&mysql);
}
