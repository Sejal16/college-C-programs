#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char str[100];
    FILE *fp1 = fopen("test1.txt","r");
    FILE *fp2 = fopen("test2.txt","w");
    if( fp1 == NULL && fp2 == NULL )
    {
        printf("Error.");
        exit(0);
    }
    else
    {
        fgets(str,100,fp1);
        printf("%s, Written in a different file",str);
        fputs(str,fp2);
        fclose(fp1);
        fclose(fp2);
    }
}
