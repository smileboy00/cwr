#include <stdio.h>
#include <math.h>
#define TEST_1 12
#define TEST_2 "test phone\
smile boy! "
#include "head.h"
#include "head.h"
//#define JUST_CHECKING1
#undef JUST_CHECKING

#define name stuff
//当有符号name出现，预处理器会把它替换成stuff

#define DEBUG_PRINT printf( "File %s line %d:"\
										" x=%d, y=%d, z=%d",\
										__FILE__, __LINE__,\
										x, y, z)
										
#define SQUARE(x) ((x) * (x))
//不加括号就变成  5+1 * 5+1 = 11 结果不一致，加上括号还是比较严谨点
void main()
{
	//printf("%d\n", TEST_1);
	//printf("%s\n", TEST_2);
	
	//double x = 48;
	//double y;
	int x = 5;
	int y = 2;
	int z;
	
	z = x * y;
	//DEBUG_PRINT;
	int a = 5;
	printf("%d\n", SQUARE(a+1));
	//printf("%d\n", SLEN);
	#ifdef JUST_CHECKING
	//printf("ok\n");
	#else
	//printf("fail\n");
	#endif
	//PR(2, "x = %.2f, y = %.4f\n", x. y);
}