#include <stdio.h>
#include <stdlib.h>


void insertion();
void deletion();
void display();
int peek();
struct node 
{
	int data;
	struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;
int main()
{

int val;
int ch=1;
while(ch!=5){
	printf("1.Insert\n2.Delete\n3.PeeK\n4.DisplaY\n5.ExiT\nEnter your choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1:
		insertion();
		break;
		case 2:
		deletion();
		break;
		case 3:
		 val=peek();
			if(val==-1)
				printf("Queue is empty\n");
			else
				printf("peek value is: %d\n",val);
			break;
		case 4:
		display();
		break;
		default:printf("Wrong choice\n");
		break;
}
}
}

void insertion()
{
	struct node *temp=(struct node*)malloc(sizeof(struct node*));
	int num;
	printf("ENter a number\n");
	scanf("%d",&num);
	temp->data=num;
	temp->next=NULL;
	if(front==NULL && rear==NULL){
		front=temp;
		rear=temp;
		
	}
	else
	{
		rear->next=temp;
		rear=temp;
	}

}
void deletion()
{
	if(front==NULL)
	{
		printf("Queue is empty,nothing to Delete\n");
	return;
	}

	printf("node Deleted\n");
	struct node *ptr=front;
	if(front==rear)
	{
		front=rear=NULL;
		free(ptr);
		return;
	}
	front=front->next;
	ptr=NULL;
	free(ptr);
}
int peek()
{
	if(front==NULL)
		return -1;
	return front->data;
}
void display(){
	if(front==NULL)
	{
		printf("Queue is empty\n");
	return;
	}
	struct node *ptr=front;
	while(ptr!=rear->next)
	{
		printf("%d\n",ptr->data );
		ptr=ptr->next;
	}

}