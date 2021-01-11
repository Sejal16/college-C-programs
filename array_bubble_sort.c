#include <stdio.h>
#include <stdlib.h>


void sort(int *ptr,int n);
int main()
{
    int *ptr,i,n;

    printf("Enter the no. of items\n");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));

     for(i=0;i<n;i++)
   {
        printf("Enter a no.\n");
        scanf("%d",(ptr+i));
    }
    sort(ptr,n);
    return 0;
}
void sort(int *ptr,int n)
{
    int i, j, t; 
  
    for (i = 0; i < n; i++) { 
  
        for (j = i + 1; j < n; j++) { 
  
            if (*(ptr + j) < *(ptr + i)) { 
  
                t = *(ptr + i); 
                *(ptr + i) = *(ptr + j); 
                *(ptr + j) = t; 
            } 
        } 
    } 
  
    for (i = 0; i < n; i++) 
        printf("%d ", *(ptr + i)); 
} 

