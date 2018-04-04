#include <stdio.h>
#define pk printf
int while_test (void)
{
	int num;
	int sum = 0;
	int status;
	char test;
	
	printf ("Please enter num. ");
	printf ("q to quit)；");
	
	#if 0
	status = scanf ("%d", &num);
	while (status == 1)
	{
		//sum = sum + num;
		sum += num;
		printf ("Please enter nex integer (q to quit): ");
		status = scanf ("%d", &num);
	}
	printf("Those intergers sum to %d.\n", sum);
	#endif
	
	#if 1
	while (scanf("%d", &num) == 1)
	{
		sum =+ num;
		printf ("223Please enter nex integer (q to quit): ");
	}
	printf("Those intergers sum to %d.\n", sum);
	#endif
	printf ("scanf function return value is %d\n", status);
	printf ("num is %d\n", num);
	return 0;
}
void test1 ()
{
	int n = 0;
	while (n < 3)
	
		pk ("n = %d\n", n);
		n++;
		pk ("Now n = %d\n", n);
	
	pk ("The loop has finished.\n");
}

void test2 ()
{
	int n = 0;
	while (n++ < 3)
		pk ("n is %d\n", n);
	pk ("Program done\n");
}

void test3 ()
{
	int true_val, false_val;
	
	true_val = (10 > 2);
	false_val = (10 == 2);
	
	printf("true = %d; false = %d\n", true_val, false_val);
}

void test4 ()
{
	int n = 3;
	
	while (n)
		printf ("%2d is true\n", n--);
	printf("%2d is false\n", n);
	n = -3;
	while (n)
		printf ("%2d is true\n", n++);
	printf ("%2d is false\n", n);
	/* 验证结论：只有0为假，其他非零值都为真 */
}

void test5 ()
{
	FILE * fp;
	
	fp = fopen ("text1.txt", "r");
	if (fp)
	{
		printf ("");
	}
	printf ("fp = %d\n", fp);
}
void main (void)
{
	test5();

	//printf ("NULL is = %d\n", (int)(NULL));
}