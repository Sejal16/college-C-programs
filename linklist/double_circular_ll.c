#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
} NODE;
NODE *create_list(NODE *);
NODE *insert_beg(NODE *);
NODE *insert_end(NODE *);
NODE *delete_beg(NODE *);
NODE *delete_end(NODE *);
NODE *delete_node(NODE *);
void display();
int main()
{
	NODE *head=NULL;
	int ch=1;
	while(ch!=11)
	{
	printf("\n1.create list\n2.insert a node at the beginning of the list\n3.insert at the end of the list\n4.Insert a node at a specific position\n5.Delete from the beginning\n6.Delete from the end\n7.Delete from any specific position\n8.Delete a node\n9.Sort the linklist\n10.Display the list\n11.Press -1 to exit\nEnter your choice: ");

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
	// case 4:
	// 	insert_position();
	// 	break;
	case 5:
		head=delete_beg(head);
		break;
	case 6:
		head=delete_end(head);
		break;
	//case 7:
	// 	delete_pos();
	// 	break;

	 case 8:
		head=delete_node(head);
		break;
	case 10:
		display(head);
		break;
	case 11:
		break;
	default:printf("wrong choice\n");
		break;
}
}
return 0;
}
NODE *create_list(NODE *head){
	NODE *ptr,*temp;
	int n;
	printf("Enter the length of the list: ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		temp=(NODE *)malloc(sizeof(NODE));
		int num;
		printf("Enter the number: ");
		scanf("%d",&num);
		temp->data=num;

		if(head==NULL)
		{
			head=temp;
			temp->next=head;
			temp->prev=head;
			
		}
		else{
			ptr=head;
			while(ptr->next!=head)
			{
				ptr=ptr->next;
			}
			ptr->next=temp;
			temp->prev=ptr;
			head->prev=temp;
			temp->next=head;

		}
}
return head;

}
NODE *insert_beg(NODE *head){
	NODE *temp=(struct node *)malloc(sizeof(struct node));
	int num;
	printf("Enter the number: ");
	scanf("%d",&num);
	temp->data=num;

	if(head==NULL)
	{
		head=temp;
			temp->next=head;
			temp->prev=head;
			printf("Node inserted\n");
			return head;
	}
	NODE *ptr=head;
	while(ptr->next!=head)
		ptr=ptr->next;
	ptr->next=temp;
	temp->prev=ptr;
	temp->next=head;
	head->prev=temp;
	head=temp;
	printf("Node inserted\n");
	return head;
}
NODE *insert_end(NODE *head){
	NODE *ptr,*temp;
	
	temp=(struct node *)malloc(sizeof(struct node));
		int num;
		printf("Enter the number: ");
		scanf("%d",&num);
		temp->data=num;
		if(head==NULL)
	{
		head=temp;
			temp->next=head;
			temp->prev=head;
			printf("Node inserted\n");
			return head;
	}
	ptr=head;
	while(ptr->next!=head)
		ptr=ptr->next;

	ptr->next=temp;
	temp->prev=ptr;
	temp->next=head;
	head->prev=temp;
	printf("Node inserted\n");
	return head;

}

NODE *delete_beg(NODE *head){
	if(head== NULL)
		{	
		printf("List is empty\n");
		return head;
	}
	if(head->next==head){
		head=NULL;
		free(head);
		printf("Node deleted\n");
		return head;
	}
	NODE *ptr=head;
	while(ptr->next!=head)
		ptr=ptr->next;
	ptr->next=head->next;
	head->next->prev=ptr;
	free(head);
	head=ptr->next;
	printf("Node deleted\n");
		return head;
}
NODE *delete_end(NODE *head){
	
	if(head== NULL)
		{	
		printf("List is empty\n");
		return head;
	}
	if(head->next==head){
		head=NULL;
		free(head);
		printf("Node deleted\n");
		return head;
	}
		NODE *ptr=head;
		while(ptr->next!=head)
			ptr=ptr->next;
		ptr->prev->next=head;
		head->prev=ptr->prev;
		free(ptr);
		printf("Node deleted\n");
		return head;

	}
	NODE *delete_node(NODE *head)
	{
		if(head== NULL)
		{	
		printf("List is empty\n");
		return head;
	}

	int num;
	printf("Enter the node which you want to delete\n");
	scanf("%d",&num);

	if(head->data==num)
	{
		head=delete_beg(head);
		return head;
	}

		NODE *ptr=head;
		while(ptr->data!=num)
		{
			ptr=ptr->next;
			if(ptr==NULL)
			{
				printf("Node not present\n");
				return head;
			}
		}
		// if(ptr->next=head)
		// {
			
		// 	return head;
		// }
		ptr->prev->next=ptr->next;
		ptr->next->prev=ptr->prev;
		ptr=NULL;
		free(ptr);
		printf("Node deleted\n");
		return head;




	}
	void display(NODE *head){
		NODE *ptr;
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
		printf("%d\n",ptr->data );
	}

}
	