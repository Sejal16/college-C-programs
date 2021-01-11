#include <stdio.h>

#include <stdlib.h>

int main()

{

 int i,n;
    float num, sum; 
    sum = 0;
	float avg;
	float max=0;



FILE *myFile;

myFile = fopen("numbers.txt", "r");





if (myFile == NULL)

{

printf("Error Reading File\n");

exit (0);

}
printf("Enter number of inputs: ");
fscanf(myFile,"%d", &n);
float arr[n];

for (i = 0; i < n; i++)

{

fscanf(myFile, "%f,", &arr[i] );


}

for (i = 0; i < n; i++)

{
if(max<arr[i])
    max=arr[i];
sum=sum+(arr[i]);

}
avg=sum/n;
fclose(myFile);

printf("The sum is : %.2f\nThe Average is : %.2f\n",sum,avg);
	printf("The greatest number is: %.2f\n",max);

return 0;

}