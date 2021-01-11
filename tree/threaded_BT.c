#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *right;
	struct node *left;
	int  thread;

} treeNode;

treeNode *leftmost(treeNode *root) ;
treeNode *newnode(treeNode *ptr,int num);
treeNode *insert(treeNode *root,int num);
void inorder(treeNode *root);
treeNode *create_thread(treeNode *root);

int main()
{
	int n;
	treeNode *root=NULL;
	int ch=1;
	while(ch!=-1)
	{
		printf("1.Insert Elements\n");
		printf("2.Display elements\n");
		printf("press -1 to EXIT\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter a number:\n");
				scanf("%d",&n);
				root=insert(root,n);
				break;
			case 2:
				inorder(root);
				break;
		}

	}
}

treeNode *newnode(treeNode *ptr,int num)
{
ptr=(treeNode *)malloc(sizeof(treeNode));
ptr->right=NULL;
ptr->left=NULL;
ptr->thread=0;
ptr->data=num;	
return ptr;
}

treeNode *insert(treeNode *root,int num)
{
if(root==NULL)
	{
		root=newnode(root,num);
	}
	if(num>root->data)
	{
		root->right=insert(root->right,num);
	}

	if(num<root->data)
	{
		root->left=insert(root->left,num);
	}
	return root;


}

void inorder(treeNode *root)
{

	create_thread(root);
	//printf("%d\n",root->data );
	if(root==NULL)
		return;
	treeNode *temp=leftmost(root);
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		if(temp->thread==1)
			temp=temp->right;
		else
			temp=leftmost(temp->right);

	}

}
treeNode *create_thread(treeNode *root)
{
	if(root==NULL)
		return NULL;
	if(root->left==NULL && root->right==NULL)
		return root;
	if(root->left!=NULL)
	{
		 treeNode *ptr=create_thread(root->left);
		 ptr->right=root;
		 ptr->thread=1;
	}
	if(root->right==NULL)
		return root;
	else
		return create_thread(root->right);
}

treeNode *leftmost(treeNode *root) 
{ 
    while (root != NULL && root->left != NULL) 
    {
        root = root->left; 
    }
    return root; 
} 
