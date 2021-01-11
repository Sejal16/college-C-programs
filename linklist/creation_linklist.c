#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node * create_list(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_position(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_pos(struct node *);
void count_nodes(struct node *);
void sort(struct node *);
void display(struct node *);

int main()
{
	struct node *head=NULL;
	int ch=1;
	while(ch!=-1)
	{
	printf("\n1.create list\n2.insert a node at the beginning of the list\n3.insert at the end of the list\n4.Insert a node at a specific position\n5.Delete from the beginning\n6.Delete from the end\n7.Delete from any specific position\n8.count the number of nodes\n9.Sort the linklist\n10.Display the list\n11.Press -1 to exit\nEnter your choice: ");

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
		head =insert_position(head);
		break;
	case 5:
		head=delete_beg(head);
		break;
	case 6:
		head=delete_end(head);
		break;
	case 7:
		head=delete_pos(head);
		break;

	case 8:
		count_nodes(head);
		break;
	case 9:
		sort(head);
		break;
	case 10:
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
		temp->next=NULL;
		if(head==NULL)
		{
			head=temp;
		}
		else{
			ptr=head;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=temp;

		}
}
return head;
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
		temp->next=NULL;
	}
	else
	{
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
		temp->next=NULL;
		if(head==NULL)
		{
			head=temp;
		}
		else{
			ptr=head;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=temp;

		}
		return head;

}
struct node *insert_position(struct node *head)
{
		int num;
		printf("Enter the number: ");
		scanf("%d",&num);
		int pos;
		printf("Enter the position: ");
		scanf("%d",&pos);
        
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->data=num;

		if(pos==1){
			temp->next=head;
			head=temp;
		}else{
		struct node *ptr=head;
		for(int i=1;i<pos-1;i++)
		{
			ptr=ptr->next;
			if(ptr==NULL){
				printf("position not found\n");
				return head;
			}}
	
		temp->next=ptr->next;
		ptr->next=temp;
}
return head;
}
struct node *delete_beg(struct node *head){
	if(head== NULL)
		printf("List is empty\n");
	else
	{
		printf("Node deleted\n");
		struct node *ptr=head;
		head=head->next;
		free(ptr);
	}
	return head;
}
struct node *delete_end(struct node *head){
		if(head== NULL)
			printf("List is empty\n");
		else if(head->next==NULL)
		{
			printf("Node deleted\n");
			
			free(head);
			head=NULL;
		}
		else{
			struct node *ptr,*preptr;
			ptr=head;
			preptr=head;
			while(ptr->next!=NULL)
			{
				preptr=ptr;
				ptr=ptr->next;

			}
			printf("Node deleted\n");
			preptr->next=NULL;
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
		head=head->next;
		free(ptr);
	}
	else
	{
		for(int i=1;i<pos;i++){
			preptr=ptr;
			ptr=ptr->next;
			if(ptr==NULL){
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
void sort(struct node *head){
//here basically we are using the concept of sorting
	struct node *ptr,*ptrnew;
	ptr=head;
	while(ptr->next!=NULL)
	{
		ptrnew=ptr->next;
		while(ptrnew!=NULL){
			if(ptr->data > ptrnew->data)
			{
				int data=ptr->data;
				ptr->data=ptrnew->data;
				ptrnew->data=data;
			}
			ptrnew=ptrnew->next;
		}
		ptr=ptr->next;
	}
	printf("list got sorted\n");
	
}
void count_nodes(struct node *head){
struct node *ptr;
int count=0;
if(head==NULL)
printf("No nodes are there\n");
else{
	ptr=head;
	
	while(ptr!=NULL)
		{
			count++;
			ptr=ptr->next;
}
}
printf("Number of nodes= %d\n",count);
}
void display(struct node *head){
	struct node *ptr;
	if(head==NULL)
		printf("no nodes to display");
	else{
		printf("List contains the following numbers: \n");
		ptr=head;
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->data );
			ptr=ptr->next;
		}
	}
}