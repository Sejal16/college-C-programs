#include <stdio.h>

int main() {
   int year;
   printf("Enter a year: ");
   scanf("%d", &year);

   if (year % 4 == 0)
   {
        if (year % 100 == 0)
          {
            if (year % 400 == 0)
               {
                printf("It is a leap and a century year");
               }
            else
               {
               printf("It is not a leap but a century year");
               }
          }
        else
            {
            printf("It is a leap but not a century year");
            }
    }
   else
        {
        printf("It is neither a leap year nor a century year");
        }
   return 0;
}
