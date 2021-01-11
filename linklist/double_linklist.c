#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
} NODE;

void create_list();
void display();
void insert_beg(); 
void insert_end();
void insert_position();
void delete_beg();
void delete_end();
void delete_pos();
void delete_list();
void reverse();
NODE *head=NULL;

int main()
{

	int ch=1;
	while(ch!=-1)
	{
	printf("\n1.create list\n2.insert a node at the beginning of the list\n3.insert at the end of the list\n4.Insert a node at a specific position\n5.Delete from the beginning\n6.Delete from the end\n7.Delete from any specific position\n8.Delete entire list\n9.reverse the link list\n10.Display the list\n11.Press -1 to exit\nEnter your choice: ");

	scanf("%d",&ch);
	printf("\n");
	switch(ch)
	{
	case 1:
		create_list();
		break;
	case 2:
		insert_beg();
	 	break;
	case 3:
		insert_end();
		break;
	case 4:
		insert_position();
		break;
	case 5:
		delete_beg();
		break;
	case 6:
		delete_end();
		break;
	case 7:
		delete_pos();
		break;

	case 8:
		delete_list();
		break;
	case 9:
		reverse();
		break;
	case 10:
		display();
		break;
	default:printf("wrong choice\n");
		break;
}
}
return 0;
}
void create_list(){
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
			temp->next=NULL;
			temp->prev=NULL;
			head=temp;

		}
		else{
			ptr=head;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=temp;
			temp->prev=ptr;
			temp->next=NULL;

		}
}

}
void display(){
	NODE *ptr;
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
void insert_beg(){
	NODE *temp=(struct node *)malloc(sizeof(struct node));
	int num;
	printf("Enter the number: ");
	scanf("%d",&num);
	temp->data=num;
	temp->prev=NULL;
	if(head==NULL)
	{
		head=temp;
		temp->next=NULL;
	}
	else
	{
		head->prev=temp;
		temp->next=head;
		head=temp;
	}
}

void insert_end(){
NODE *ptr,*temp;
	
	temp=(struct node *)malloc(sizeof(struct node));
		int num;
		printf("Enter the number: ");
		scanf("%d",&num);
		temp->data=num;
		
		if(head==NULL)
		{
			head=temp;
			temp->next=NULL;
			temp->prev=NULL;
		}
		else{
			ptr=head;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=temp;
			temp->prev=ptr;
			temp->next=NULL;
		}


	}
void insert_position()
{
		int num;
		printf("Enter the number: ");
		scanf("%d",&num);
		int pos;
		printf("Enter the position: ");
		scanf("%d",&pos);
        
        NODE *temp=(struct node *)malloc(sizeof(struct node));
        temp->data=num;

		if(pos==1){
			
			head->prev=temp;
			temp->next=head;
			temp->prev=NULL;
			head=temp;
			//insert_beg();

		}else{
		NODE *ptr = head;
		int i=1;
        for ( i = 1;i < pos-1 && ptr!=NULL ; i++)
        {
                ptr = ptr->next;
        }
        if(ptr==NULL)
	{
		printf("Invalid position\n");
		return;
	}	
   //      if(ptr->next==NULL){
        	
			// temp->prev=ptr;
			// temp->next=NULL;
			// ptr->next=temp;
   //      }
       if(temp!=NULL){
        temp->next=ptr->next;
        temp->prev=ptr;
        ptr->next = temp;

    }
   
}
}

 void delete_beg(){
	if(head== NULL)
		printf("List is empty\n");
	if(head->next==NULL){
		printf("Node deleted");
		head=NULL;

	}
	else
	{
		printf("Node deleted\n");
		NODE *ptr=head;
		head=head->next;
		head->prev=NULL;
		free(ptr);
	}
}
void delete_end(){
		if(head== NULL)
		{	printf("List is empty\n");
		return;
	}
		else if(head->next==NULL)
		{
			printf("Node deleted\n");
			
			
			head=NULL;
			return;
			
		}
		else{
			NODE *ptr;
			ptr=head;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			printf("Node deleted\n");
			ptr->prev->next=NULL;
			ptr=NULL;
			free(ptr);
			return;
		}
	}
	void  delete_pos(){
	if(head==NULL){
		printf("List is empty\n");
		return;
	}
	NODE *ptr=head;
	
	int pos;
	printf("Enter the position of the node which you want to delete: ");
	scanf("%d",&pos);
	if(pos==1)
	{	ptr=head;
		printf("Node deleted\n");
		head=head->next;
		head->prev=NULL;
		//ptr=NULL;
		free(ptr);
		return;

	} 
	else
	{
	
		int i;
		for( i=1;i<pos && ptr!=NULL;i++){
		
			ptr=ptr->next;
			
		}
			
	if(ptr==NULL)
	{
		printf("Invalid position\n");
		return;
	}	
		if(ptr->next==NULL)
		{
			ptr->prev->next=NULL;
			//ptr=NULL;
			free(ptr);
			return;
		}
		else if(ptr!=NULL){
		printf("Node deleted\n");
		ptr->prev->next=ptr->next;
		ptr->next->prev=ptr->prev;
		//ptr=NULL;
		free(ptr);
		return;
	}
	else
	{
		printf("Invalid position\n");
		return;
	}
	
}}
void delete_list(){
	while(head!=NULL)
		delete_beg();
}
void reverse()
{
	NODE *ptr=head;
	NODE *temp=NULL;
	
	while(ptr!=NULL){
		temp=ptr->prev;
		ptr->prev=ptr->next;
		ptr->next=ptr;
		ptr=ptr->prev;

	}
	if(temp!=NULL)
		head=temp->prev;
}