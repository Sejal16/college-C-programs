#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *create_list(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_pos(struct node *);
void display(struct node *);

int main()
{
	printf("Circular Linklist\n");
	struct node *head=NULL;
	int ch=1;
	while(ch!=-1)
	{
	printf("\n1.create list\n2.insert a node at the beginning of the list\n3.insert at the end of the list\n4.Delete from the beginning\n5.Delete from the end\n6.Delete from any specific position\n7.Display the list\n9.Press -1 to exit\nEnter your choice: ");

	scanf("%d",&ch);
	printf("\n");
	switch(ch)
	{
	case 1:
		head=create_list(head);
		break;
	case 2:
		head=insert_beg(head);
		break;
	case 3:
		head=insert_end(head);
		break;
	case 4:
		head=delete_beg(head);
		break;
	case 5:
		head=delete_end(head);
		break;
	case 6:
		head=delete_pos(head);
		break;
    case 7:
		display(head);
		break;
	default:printf("wrong choice\n");
		break;
}
}
return 0;
}
struct node *create_list(struct node *head){
	struct node *ptr,*temp;
	int n;
	printf("Enter the length of the list: ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		int num;
		printf("Enter the number: ");
		scanf("%d",&num);
		temp->data=num;
		if(head==NULL)
		{
			head=temp;
			temp->next=head;
		}
		else{
			ptr=head;
			while(ptr->next!=head)
			{
				ptr=ptr->next;
			}
			ptr->next=temp;
			temp->next=head;

		}
}
return head;
}
void display(struct node *head){
	struct node *ptr;
	if(head==NULL)
		printf("no nodes to display");
	else{
		printf("List contains the following numbers: \n");
		ptr=head;
		while(ptr->next!=head)
		{
			printf("%d\n",ptr->data );
			ptr=ptr->next;
		}
	}
		printf("%d\n",ptr->data);
	
}
struct node *insert_beg(struct node *head){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	int num;
	printf("Enter the number: ");
	scanf("%d",&num);
	temp->data=num;
	if(head==NULL)
	{
		head=temp;
		temp->next=head;
	}
	else
	{
		struct node *ptr=head;
		while(ptr->next!=head)
			ptr=ptr->next;
		ptr->next=temp;
		temp->next=head;
		head=temp;
	}
return head;
}
struct node *insert_end(struct node *head){
struct node *ptr,*temp;
	
	temp=(struct node *)malloc(sizeof(struct node));
		int num;
		printf("Enter the number: ");
		scanf("%d",&num);
		temp->data=num;
		
		if(head==NULL)
		{
			head=temp;
			temp->next=head;
		}
		else{
			ptr=head;
			while(ptr->next!=head)
			{
				ptr=ptr->next;
			}
			ptr->next=temp;
			temp->next=head;

		}
		return head;

}
struct node *delete_beg(struct node *head){
	if(head== NULL)
		printf("List is empty\n");
	else
	{  
		struct node *ptr=head;
		printf("Node deleted\n");
		while(ptr->next!=head)
			ptr=ptr->next;
		ptr->next=head->next;
		free(head);
		head=ptr->next;
	}
	return head;
}
struct node *delete_end(struct node *head){
		if(head== NULL)
			printf("List is empty\n");
		else if(head->next==head)
		{
			printf("Node deleted\n");
			
			free(head);
			head=NULL;
		}
		else{
			struct node *ptr,*preptr;
			ptr=head;
			preptr=head;
			while(ptr->next!=head)
			{
				preptr=ptr;
				ptr=ptr->next;

			}
			printf("Node deleted\n");
			preptr->next=head;
			free(ptr);
			ptr=NULL;
		}
		return head;
	}
struct node *delete_pos(struct node *head){
	if(head==NULL){
		printf("List is empty\n");
		return head;
	}
	struct node *ptr=head;
	struct node *preptr=head;
	int pos;
	printf("Enter the position of the node which you want to delete: ");
	scanf("%d",&pos);
	if(pos==1)
	{	
		printf("Node deleted\n");
		while(ptr->next!=head)
			ptr=ptr->next;
		ptr->next=head->next;
		free(head);
		head=ptr->next;
	}
	else
	{
		for(int i=1;i<pos;i++){
			preptr=ptr;
			ptr=ptr->next;
			if(ptr==head){
				printf("position id out of range\n");
				return head;
		}}
		printf("Node deleted\n");
		preptr->next=ptr->next;
		ptr=NULL;
		free(ptr);
	}
	return head;
}