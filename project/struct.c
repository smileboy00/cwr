#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 41
#define MAXAUTL 31
#define SIZE 20
struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

#ifdef STRUCET_DEFINE
int main(void)
{
	struct book library;
	printf("Please enter the book title.\n");
	//fgets(library.title, SIZE, stdin);//访问结构体成员 .  ->的区别？
	gets(library.title);
	printf("Now enter the author.\n");
	//fgets(library.author, SIZE, stdin);//linux 使用gets会出错
	gets(library.author);//fgets会将换行符也读进去，printf出来会多个换行符感觉会很奇怪。
	printf("Now enter the value.\n");
	scanf("%f",&library.value);//gets 和 scanf 的区别？http://blog.csdn.net/u014536527/article/details/48878123
	printf("%s by %s: $%.2f\n",library.author,library.title,library.value);
	printf("%s : \"%s\" ($%.2f)\n",library.author,library.title,library.value);//""的转义符在前面加\
	
	printf("Done.\n");
	return 0;
}
#endif


#ifdef STRUCT_INIT
int main(void)
{
	/* struct book library = {
		"book name",
		"cwr",
		1.23
	}; *///类似数组的初始化 .value相当于数组的下标。
	
	struct book library = {
		.value = 12.99,
		.author = "cwr",
		99.8
	};//实际测试赋值的值会被覆盖 value为99.8
	
	
	printf("#book# %.3f\n",library.value);
	return 0;
}
#endif
