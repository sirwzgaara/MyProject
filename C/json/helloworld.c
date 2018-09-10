
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

void main()
{
    char * string =
        "{\"family\":[\"father\",\"mother\",\"brother\",\"sister\",\"somebody\"]}";
    cJSON * json = cJSON_Parse(string);
    char * buf1 = NULL;
    char * buf2 = NULL;
    
    buf1 = cJSON_Print(json);
    buf2 = cJSON_PrintUnformatted(json);

    printf("string size is %d\n", strlen(string));
    printf("buf1 size is %d\n", strlen(buf1));
    printf("buf2 size is %d\n", strlen(buf2));
    printf("buf2 is %s\n", buf2);
    printf("string is %s\n", string);
}
