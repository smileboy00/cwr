#include <stdio.h>
void main(void)
{
    if(0)
{
    //const int a = 10;
    int a = 10;
    int b = 11;

    a = b;
    
    printf("a = %d\n", a);
}


    int a[10]={0};

    printf("a[0] address : %p\n", &a[0]);
    printf("a head of address : %p\n", a);

}
