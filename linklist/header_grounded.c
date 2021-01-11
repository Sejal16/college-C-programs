//  HEADER LINKLIST means that the head/start pointer will not be equal to the first node.Before the first node we descrbe one //  more node where we can store any information related to our list
//   eg: no of nodes/largest number
// Two types of header ll:
//		GROUNDED HEADER LINKLIST
//		Circular header linked list

#include<stdio.h>
#include<stdlib.h>
void create_list();
void insert();
void display();
typedef struct header HEADER;

typedef struct node{
	int data;
	struct node *next;
}NODE;

struct header{
	int count;
	int max;
	int min;
	struct node *next;
};

HEADER start;
NODE *last=NULL;

int main(){
	
			start.count=0;
			start.max=0;
			start.min=0;
			start.next=NULL;
	int ch=1;
	while(ch!=4)
	{
	printf("\n1.create list\n2.insert a node\n3.Display\n4.Exit\n\nEnter your choice: ");
	scanf("%d",&ch);
	printf("\n");
	switch(ch)
	{
	case 1:
		create_list();
		break;
	case 2:
		insert();
	 	break;
	case 3:
		display();
		break;
	case 4:
	 break;
}
}
return 0;
}
void create_list(){

	int n;
	printf("Enter the length of the list: ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		NODE *temp=(struct node *)malloc(sizeof(struct node));
		int num;
		printf("Enter the number: ");
		scanf("%d",&num);
		temp->data=num;
		temp->next=NULL;
		if(start.next==NULL)
		{
			start.next=temp;
            last =temp;
            start.count=start.count+1;
            start.min=temp->data;
            start.max=temp->data;
			
		}
		else{
			last->next=temp;
			last=temp;
			start.count=start.count+1;
			if(start.max<temp->data)
				start.max=temp->data;
			if(start.min>temp->data)
				start.min=temp->data;
}


}
}
void insert(){
	  NODE *temp=(struct node *)malloc(sizeof(struct node));
		int num;
		printf("Enter the number: ");
		scanf("%d",&num);
		temp->data=num;
		temp->next=NULL;
		if(start.next==NULL)
		{
			start.next=temp;
            last =temp;
            start.count=start.count+1;
            start.min=temp->data;
            start.max=temp->data;
			
		}
		else{
			last->next=temp;
			last=temp;
			start.count=start.count+1;
			if(start.max<temp->data)
				start.max=temp->data;
			if(start.min>temp->data)
				start.min=temp->data;
}
}
void display(){
	printf(" Total= %d ",start.count);
            printf(" Max= %d  ",start.max);
            printf(" Min= %d  ",start.min);
	NODE *ptr=start.next;
	while(ptr!=NULL)
	{	printf("\n  %d\n",ptr->data );

	ptr=ptr->next;
}
}
