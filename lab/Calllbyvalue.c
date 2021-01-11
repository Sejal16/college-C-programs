#include <stdio.h>
void swap(int a, int b);
void swap1(int *c, int *d);

void  main()
{
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;
    printf("Before swapping the values in main a = %d, b = %d\n",a,b);
    swap(a,b);
    printf("After swapping values in main a = %d, b = %d\n",a,b);

     printf("Before swapping the values in main c = %d, d = %d\n",c,d);
    swap1(&c,&d);
    printf("After swapping values in main c = %d, d = %d\n",c,d);


}
void swap (int a, int b)
{
    int temp;
    temp = a;
    a=b;
    b=temp;
    printf("After swapping values in function a = %d, b = %d\n",a,b);
}


void swap1 (int *c, int *d)
{
    int temp;
    temp = *c;
    *c=*d;
    *d=temp;
    printf("After swapping values in function a = %d, b = %d\n",*c,*d);
}
