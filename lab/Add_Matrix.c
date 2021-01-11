#include <stdio.h>
int main()
{
    int r1, c1, r2, c2, i, j, sum = 0;
    int A[10][10], B[10][10], Add[10][10];

    printf("Enter number of rows and columns of first matrix\n");
    scanf("%d%d", &r1, &c1);


    printf("Enter number of rows and columns of second matrix\n");
    scanf("%d%d", &r2, &c2);

    if (r1 != r2 || c1 !=c2)
        {
        printf("The Addition isn't possible.\n");
        }
    else
    {
        printf("Enter elements of first matrix\n");

    for (i = 0; i < r1; i++)
        {
        for (j = 0; j < c1; j++)
            {
             scanf("%d", &A[i][j]);
            }
        }
    printf("Enter elements of second matrix\n");

    for (i = 0; i < r2; i++)
        {
        for (j = 0; j < c2; j++)
            {
            scanf("%d", &B[i][j]);
            }
        }

    for (i = 0; i < r1; i++)
    {
      for (j = 0; j < c2; j++)
        {
        Add[i][j]=A[i][j]+B[i][j];
        }

    }

    printf("Addition of the matrices:\n");

    for (i = 0; i < r1; i++)
     {
      for (j = 0; j < c2; j++)
       {
        printf("%d\t", Add[i][j]);
       }

      printf("\n");
     }
  }

  return 0;
}
