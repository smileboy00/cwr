#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  10

struct book{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	
};    //模板跟赋值不要搞混掉！！！
#ifdef ARRAY_STRUCT
void main(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index;
	
	printf("Please enter the book title.\n");
	printf("Press [enter] at the start of a line to stop.\n");
	
	while (count < MAXBKS && gets(library[count].title) != NULL && library[count].title[0] != '\0')//while 的用法 按回车就是表示输入空字符串，不要理解成输入\n
	{
		printf("Now enter the author.\n");
		gets(library[count].author);
		printf("Now enter the value.\n");
		scanf("%f",&library[count++].value);//实际输入比如：11.1\n 但scanf会把\n留在输入流中。
		//导致下一次循环程序会误以为用户回车输入空字符串导致结束循环。
		while (getchar() != '\n')// continue的用法和该语法结构的用途。
		//getchar()的作用是取出缓冲区里的'\n'或' '字符
			continue;	//清空输入行
		if (count < MAXBKS)
		printf("Enter the next title.\n");
	}
	if (count > 0)
	{
		printf("Here is the list of your books:\n");
		for (index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
	}
	else
		printf("No books?Too bad.\n");
	
}
#endif

#ifdef NEST_STRUCT
#define LEN 20
const char * msgs[5] =
{	//指针数组
	" Thank you for the wonderful evening",
	"You certainli prove that a",
	"is a spacial kind of guy. we must get together",
	"over a delicious",
	" and have a few laughs"
};
struct names {//第一个结构
	char first[LEN];
	char last[LEN];
};
struct guy {//第二个结构
	struct names handle;//嵌套结构
	char favfood[LEN];
	char job[LEN];
	float income;
};
void main(void)
{
	struct guy fellow = {//初始化一个变量
		{"Ewen" , "Villard"},
		"grilled salmon",
		"personality coach",
		158112.00
	};
	
	printf("Dear %s, \n\n", fellow.handle.first);
	printf("%s%s.\n", msgs[0], fellow.handle.first);
	//访问嵌套结构只需要使用两次点运算符
	printf("%s%s\n", msgs[1], fellow.job);
	printf("%s\n", msgs[2]);
	printf("%s%s%s", msgs[3], fellow.favfood, msgs[4]);
	if (fellow.income > 150000.0)
		puts("!!");
	else if (fellow.income > 75000.0)
		puts("!");
	else
		puts(".");
	printf("\n%40s%s\n", " ", "See you soon, ");
	printf("%40s%s\n", " ", "Shalala");
}
#endif

//向函数传递结构体成员
#ifdef FUNC_STRUCT
struct test{
	int a;
	int b;
};
int sum(int a , int b)
{
	return a+b;
}
int mult(struct test * p)
{
	return (p->a * p->b );
	//指针使用->去访问结构体成员 普通结构体成员的访问为点运算符
}
void main(void)
{
	struct test count = {
		10,
		12
	};
	//先创建结构体模板，然后具体化结构体并初始化，创建一个结构体指针并将目标结构体名字的地址赋值给结构体指针
	//区分数组名为地址，结构体名不是地址，所以需要在前面加取地址符&
	struct test * num;
	num = &count;
	int total = 0;
	//total = sum(count.a, count.b);
	total = mult(num);
	printf("结果 = %d\n", total);
}
#endif

//在结构体中使用字符数组还是字符指针
#ifdef TEST_1
#define LEN 20
struct name {
	char first[LEN];
	char last[LEN];
};
struct pnames {
	char * first;
	char * last;
};
//字符数组创造了40个字节的空间来存储，而字符指针只有8个字节来存储地址而已
//字符串可以存储在字符串常量的任何地方。
//panmes结构体指针应该用于管理已经分配过空间的字符串，这样操作比较安全可靠
void main()
{
	/* struct name veep = {"ccc", "rrr"};
	struct pnames hello = {"hi", "smile"};
    printf("%s and %s\n", veep.first, hello.first); */
	
	struct name acc;
	struct pnames att;
	puts("Enter the last name of your acc:");
	scanf("%s", acc.last);
	puts("Enter the last name of you att:");
	scanf("%s", att.last);//这样操作非常危险，结构来存储数据最后使用字符数组
	//结构体指针的好处？
	}
#endif

//把结构体内容保存到文件中
#ifdef TEST_2
void main(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index, filecount;
	FILE * pbooks;
	int size = sizeof(struct book);
	
	if((pbooks = fopen("book.txt", "a+b")) == NULL)
	{
		fputs("Cant open file\n", stderr);
		exit(1);
	}
	rewind(pbooks);
	//如果是: fread(buff, size, 1, fp)返回1表示读取了size字节，返回0表示读取数量不够size字节
	while(count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		if (count == 0)
			puts("Current contents of book.txt: ");
		printf("%s by %s: $%.2f\n", library[count].title,
			library[count].author, library[count].value);
	}
}
#endif