
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"


void main()
{
    cJSON * json = NULL;
    json = cJSON_CreateObject();
    cJSON * array = NULL;
    cJSON_AddItemToObject(json, "start", array = cJSON_CreateArray());
}
