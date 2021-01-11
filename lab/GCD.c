#include<stdio.h>
#include<stdlib.h>
void main()
{
    int a,b,gcd;
    printf("\nEnter the two numbers : ");
    scanf("%d %d",&a,&b);
    int i;
    for(i = 1; i <= a && i <= b; i++)
        {
         if((a % i == 0) && (b % i == 0))
            {
                gcd = i;
            }
        }
    printf("\nGCD of %d and %d is %d\n ",a,b,gcd);


}
