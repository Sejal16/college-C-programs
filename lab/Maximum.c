#include<stdio.h>
int maximum(int []);
int n;
int main()
{   int a[10],max,i;
    printf(" Input the number of elements to be stored in the array :");
    scanf("%d",&n);

    printf(" Input %d elements in the array :\n",n);
       for(i=0;i<n;i++)
        {
	      printf(" element - %d : ",i);
	      scanf("%d",&a[i]);
	    }
    max=maximum(a);

    printf(" The largest element in the array is : %d\n\n",max);
    return 0;
}
int maximum(int a[])
{
    int i=1,max;
    max=a[0];
    while(i < n)
	{
      if(max<a[i])
           max=a[i];
      i++;
    }
    return max;
}
