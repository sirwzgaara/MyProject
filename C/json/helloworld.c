
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

enum operation
{
	add,
	del,
	modify,
	operation_butt
};

enum configuration
{
	/* global conf */
	dit,
	dit_count,
	ping_check,
	aio_enable,
	fp_enable,
	lps_enable,
	host,
	class,

	/* wire_conf */
	share_notwork = 30,
	subnet,
	pool,
	conf_butt
};

struct test
{
	int conf_type;		//��������
	int operation;		//��������
	int global_value;	//����ȫ�����ã�����ֵ
};

void main()
{
    cJSON * json = NULL;
    json = cJSON_CreateObject();
    cJSON * array = NULL;
    cJSON_AddItemToObject(json, "start", array = cJSON_CreateArray());
}
