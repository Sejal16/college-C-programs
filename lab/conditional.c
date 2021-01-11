#include<stdio.h>
int main()
{
    int n,rem;
    printf("Enter a  number\n");
    scanf("%d",&n);
    rem=n%2;
    //Conditional Operator
    rem==0?printf("Even"):printf("Odd");
    //If else
    if (rem==0)
    {
        printf("\nEven");
    }
    else
    {
        printf("\nOdd");
    }
    return 0;
}
