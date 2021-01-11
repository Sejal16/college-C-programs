#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *next;
};
struct node *push(struct node *);
void display(struct node *);
struct node *pop(struct node *);
int peek(struct node *);

int main()
{
struct node *top=NULL;
int val;
int ch=1;
while(ch!=5){
	printf("1.PusH\n2.PoP\n3.PeeK\n4.DisplaY\n5.ExiT\nEnter your choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			top=push(top);
			break;
		case 2:
			top=pop(top);
			break;
		case 3:
			 val=peek(top);
			if(val==-1)
				printf("Stack is empty\n");
			else
				printf("peek value is: %d\n",val);
			break;
		case 4:
			display(top);
			break;
		case 5:
		break;
		default:printf("Wrong choice\n");
		break;
	}
}
}
struct node *push(struct node *top){
	
	struct node *temp=(struct node*)malloc(sizeof(struct node*));
	int num;
	printf("ENter a number\n");
	scanf("%d",&num);
	temp->data=num;
	temp->next=top;
	top=temp;
	return top;
	}

void display(struct node *top)
{
	if(top==NULL){
		printf("Stack is empty\n");
		return;
	}
	while(top!=NULL)
	{
		printf("%d\n",top->data );
		top=top->next;
	}
}
struct node *pop(struct node *top){
	if(top==NULL){
		printf("Stack is empty\n");
		return top;
	}
	printf("Element got popped out\n");
	struct node *ptr=top;
	top=top->next;
	free(ptr);
	return top;
}
int peek(struct node *top)
{
	if(top==NULL)
		return -1;
	return top->data;
}