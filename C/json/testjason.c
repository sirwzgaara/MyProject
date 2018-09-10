
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

/* 从一个json格式解析到字符串并打印出来 */
void func1()
{
    char * data = "{\"love\":[\"LOL\",\"Go shopping\"]}";
    cJSON * json = cJSON_Parse(data);

    char * json_data = NULL;
    printf("data:%s\n", json_data = cJSON_Print(json));
    free(json_data);
    cJSON_Delete(json);
}

/* 打印一个json，并且写入json格式的文件 */
void func2()
{
    char * char_json = "{\"habit\":\"lol\"}";
    cJSON * json = cJSON_Parse(char_json);
    char *buf = NULL;

    printf("data:%s\n", buf = cJSON_Print(json));
    FILE * fp = fopen("func2.json", "w");
    fwrite(buf, strlen(buf), 1, fp);

    fclose(fp);
    free(buf);
    cJSON_Delete(json);
}

/* 生成一个结构复杂的json文件 */
void func3()
{
    /* 创建一个空对象 */
	cJSON * json = cJSON_CreateObject();
    /* 向对象中加入一个键值对 */
	cJSON_AddItemToObject(json, "name", cJSON_CreateString("王大锤"));
    /* 加入另一个键值对，注意是number类型的 */
	cJSON_AddNumberToObject(json, "age", 29);

    /* 创建一个数组插入到json中 */
    cJSON *array = NULL;
	cJSON_AddItemToObject(json, "love", array = cJSON_CreateArray());
	cJSON_AddItemToArray(array, cJSON_CreateString("LOL"));
	cJSON_AddItemToArray(array, cJSON_CreateString("NBA"));
	cJSON_AddItemToArray(array, cJSON_CreateString("Go shopping"));

	cJSON_AddNumberToObject(json, "score", 59);
	cJSON_AddStringToObject(json, "address", "beijing");

    /* 将json结构格式化到缓冲区 */
	char *buf = cJSON_Print(json);

    /* 打开文件并写入json内容 */
	FILE * fp = fopen("create.json", "w");
	fwrite(buf, strlen(buf), 1, fp);
	free(buf);
	fclose(fp);
	cJSON_Delete(json);
}

/* 在数组元素内部嵌入json对象 */
void func4()
{
	cJSON * json = cJSON_CreateObject();
	cJSON_AddStringToObject(json, "country", "china");

	cJSON * array = NULL;	
	cJSON_AddItemToObject(json,"stars",array = cJSON_CreateArray());

	cJSON * obj = NULL;
	cJSON_AddItemToArray(array, obj = cJSON_CreateObject());
	cJSON_AddItemToObject(obj, "name", cJSON_CreateString("Faye"));
	cJSON_AddStringToObject(obj, "address", "beijing");

	cJSON_AddItemToArray(array, obj = cJSON_CreateObject());
	cJSON_AddItemToObject(obj, "name", cJSON_CreateString("andy"));
	cJSON_AddItemToObject(obj, "address", cJSON_CreateString("HK"));

	cJSON_AddItemToArray(array, obj = cJSON_CreateObject());
	cJSON_AddStringToObject(array, "name", "eddie");
	cJSON_AddStringToObject(obj, "address", "TaiWan");

	FILE *fp = fopen("func4.json", "w");
	char * buf = cJSON_Print(json);
	fwrite(buf, strlen(buf), 1, fp);
	fclose(fp);
	cJSON_Delete(json);
}

/* 解析json，查找数据 */
void func5()
{
	char * string = 
		"{\"family\":[\"father\",\"mother\",\"brother\",\"sister\",\"somebody\"]}";
	cJSON * json = cJSON_Parse(string);
	cJSON * node = NULL;

    /* 第一种判断是否有key的方法 */
	node = cJSON_GetObjectItem(json, "family");
	if (NULL == node)
	{
		printf("family node == NULL\n");
	}
	else
	{
		printf("found family node\n");
	}

	node = cJSON_GetObjectItem(json, "fmail");
	if (NULL == node)
	{
		printf("fmail node == NULL\n");
	}
	else
	{
		printf("found fmail node\n");
	}
	
    /* 第二种判断是否有key的方法 */
	if (1 == cJSON_HasObjectItem(json, "family"))
	{
		printf("found family node\n");
	}
	else
	{
		printf("not found family node\n");
	}

	if (1 == cJSON_HasObjectItem(json, "fmail"))
	{
		printf("found fmail node\n");
	}
	else
	{
		printf("not found fmail node\n");
	}

    /* 获取某个节点 */
	node = cJSON_GetObjectItem(json, "family");
    /* 用这种方法判断节点类型，调用api获取数组大小 */
	if (node->type == cJSON_Array)
	{
		printf("array size if %d\n", cJSON_GetArraySize(node));
	}

	cJSON * tnode = NULL;
	int size = cJSON_GetArraySize(node);
	int i;

    /* 遍历值的第一种方法 */
	for (i = 0; i < size; i++)
	{
        /* 获取数组里面的每个项目 */
		tnode = cJSON_GetArrayItem(node, i);
        /* 若值是string，打印出来 */
		if (tnode->type == cJSON_String)
		{
			printf("value[%d]:%s\n", i, tnode->valuestring);
		}
		else
		{
			printf("node's type is not string\n");
		}
	}

    /* 第二种方法，调用api遍历节点 */
	cJSON_ArrayForEach(tnode, node)
	{
		if (tnode->type == cJSON_String)
		{
			printf("in forEach: value:%s\n", tnode->valuestring);
		}
		else
		{
			printf("node's type is not string\n");
		}
	}
}


void main()
{
    func5();
}
