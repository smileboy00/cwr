#include <stdio.h>
#include "../test.h"
#include "test.h"

void func()
{
	static int c1;
	c1 = 10;
	
	LOG("FUNC C1 = %d\n", c1);
}
typedef enum
{
	red,//注意是，结构体声明是；如果成员1没有赋值，那么第一个元素就为0，其他成员以此类推累加起来。
	blue,
	green,
}enum_test;

#ifdef TEST1
void main(void)
{
	char a;
	enum_test my_enum = green;
	LOG("MY_ENUM IS %d\n", my_enum);
	//LOG("main c1 = %d\n",c1);
	
}
#endif

void main(void)
{
	//int *p = NULL;
	char s[100]={0};
	scanf("%s", s);
	LOG("s = %s\n", s);
}