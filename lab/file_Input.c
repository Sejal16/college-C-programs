#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char str[100];
    printf("Enter the string:\n");
    fgets(str,100,stdin);
    FILE *fp = fopen("input.txt","w");
    if( fp == NULL )
    {
        printf("Error.");
        exit(0);
    }
    else
    {
        fputs(str,fp);
        fclose(fp);
    }
}
