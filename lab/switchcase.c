#include<stdio.h>
int main()
{
    char grade;
    printf("Enter your grade\n");
    scanf("%c",&grade);
    switch (grade)
    {
        case 'A':
            printf("Yours marks are between 90 and 100");
            break;
        case 'B':
            printf("Yours marks are between 80 and 90");
            break;
        case 'C':
            printf("Yours marks are between 70 and 80");
            break;
        case 'D':
            printf("Yours marks are between 60 and 70");
            break;
        default:
            printf("Sorry ! You have failed.");
    }
    return 0;
}

