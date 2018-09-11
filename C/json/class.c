
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

void main()
{
    cJSON * json = cJSON_CreateObject();
    cJSON * tmp1 = NULL;
    cJSON * tmp2 = NULL;
    cJSON * tmp3 = NULL;
    cJSON * tmp4 = NULL;

    /* 向object中加入一个数据，key是class，值是一个新建的object */
    cJSON_AddItemToObject(json, "class", tmp1 = cJSON_CreateObject());

    cJSON_AddStringToObject(tmp1, "name", "option222");
    cJSON_AddStringToObject(tmp1, "attribute", "add");
    cJSON_AddStringToObject(tmp1, "match if", "option cm-class = aa");
    cJSON_AddStringToObject(tmp1, "match if", "option dhcp-message-type = 1");
    
    char *buf = cJSON_Print(json);
    printf("%s\n", buf);
}
