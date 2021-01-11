#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
int main()
{
	struct node *head=NULL;
	head =(struct node *)malloc(sizeof(struct node));
	int n;
	 printf("Enter a number: ");
	 scanf("%d/n",&n);
	 head->data=n;
	head->next=NULL;

	printf("%d",head->data);
	return 0;

}