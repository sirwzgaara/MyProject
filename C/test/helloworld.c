
#ifdef _cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <fcntl.h>		//for open
#include <stdlib.h>		//for printf
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <ctype.h>
#include <errno.h>
#include <assert.h>
#include <hiredis/hiredis.h>

void func()
{
    int *a[10] = {0};
    if (!a)
        printf("dd\n");
}

void main()
{
    func();
}




#ifdef _cplusplus
}
#endif


