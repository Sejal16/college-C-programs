#include <stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node *left;
	struct node *right;
	
}bstnode;

bstnode *newnode(bstnode *,int );
bstnode *insert(bstnode *,int );
void search(bstnode *,int );
bstnode *delete(bstnode *,int );
bstnode *findMin(bstnode *);
bstnode *findMax(bstnode *);
void preorderTraversal(bstnode *);
void inorderTraversal(bstnode *);
void postorderTraversal(bstnode *);
int height(bstnode *);
int totalNodes(bstnode *);
int totalExternalNodes(bstnode *);
int totalInternalNodes(bstnode *);
bstnode *mirrorImage(bstnode *);
bstnode *deleteTree(bstnode *);

int main()
{   
	bstnode *ptr;
	int n;
	bstnode *root=NULL;
	int ch=1;
	while(ch!=-1)
	{
		printf("\n1.Insertion\n2.Search an element in the list\n3.delete a node\n4.smallest number in tree\n5.largest number in tree\n6.Preorder tree traversal\n7.Inorder tree traversal\n8.Postorder tree traversal\n9.height of the tree\n10.Number of nodes\n11.Number of external nodes\n12.Number of internal nodes\n13.mirror image\n14.Delete tree\nnumbEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter a number:\n");
				scanf("%d",&n);
				root=insert(root,n);
				break;
			case 2:
				printf("Enter the target element which need to be searched: \n");
				scanf("%d",&n);
				search(root,n);
				break;
			case 3:
				printf("Enter the element which need to be deleted: \n");
				scanf("%d",&n);
				root=delete(root,n);
				break;
			case 4:
				ptr=findMin(root);
				printf("Smallest number is %d\n",ptr->data );
				break;
			case 5:
				ptr=findMax(root);
				printf("Largest number is %d\n",ptr->data );
				break;
			case 6:
				printf("\n The elements of the tree are : \n");
				preorderTraversal(root);
				printf("\n");
				break;
    		case 7:
				printf("\n The elements of the tree are : \n");
				inorderTraversal(root);
				printf("\n");
				break;
    		case 8:
				printf("\n The elements of the tree are : \n");
				postorderTraversal(root);
				printf("\n");
				break;
			case 9:
				printf("height of the tree is %d\n",height(root));
				break;
			case 10:
				printf("\n Total no. of nodes = %d", totalNodes(root));
				break;
			case 11:
				printf("\n Total no. of external nodes = %d",totalExternalNodes(root));
				break;
			case 12:
				printf("\n Total no. of internal nodes = %d",totalInternalNodes(root));
				break;
			case 13:
				root = mirrorImage(root);
				break;
			case 14:
				root = deleteTree(root);
				break;
		}
	}

}
bstnode *newnode(bstnode *temp,int num)
{
	temp=(bstnode *)malloc(sizeof(bstnode));
	temp->data=num;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
bstnode *insert(bstnode *root,int num)
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

void search(bstnode *root,int target){

	if(root==NULL)
	{
		printf("Number not found\n");
		return;
	}
	if(target==root->data)
	{
	printf("Number  found\n");
		return;	
	}
	else if(target<root->data)
		search(root->left,target);
	else
		search(root->right,target);
}
bstnode *delete(bstnode *root,int num){
	if(root==NULL)
	{
		printf("Node not present");
		return root;
	}
	else if(num<root->data)
		root->left=delete(root->left,num);
	else if(num>root->data)
		root->right=delete(root->right,num);
	else{            //when we found the number

		// condition 1: when no child i.e leaf node
		if(root->left==NULL && root->right==NULL){
			  free(root);
			  root=NULL;
		}
		//condition 2: single child
		else if(root->left==NULL){
			bstnode *ptr=root;
			root=root->right;
			free(ptr);
	    }
	    else if(root->right==NULL){
			bstnode *ptr=root;
			root=root->left;
			free(ptr);
	    }
	    //condition 3:when it root has 2 child
	    else{
	    	bstnode *ptr;
	    	ptr=findMin(root->right);  // alternative- we can replace with the max number of the left node
	    	root->data=ptr->data;
	    	root->right=delete(root->right,ptr->data);

	    }
	}
	return root;
}
bstnode *findMin(bstnode *root)
{
	if(root==NULL )
		{
			printf("Tree is empty\n");
			return root;
		}
	if(root->left==NULL)
		return root;
	return root=findMin(root->left);
}
bstnode *findMax(bstnode *root)
{
	if(root==NULL )
		{
			printf("Tree is empty\n");
			return root;
		}
	if(root->right==NULL)
		return root;
	return root=findMax(root->right);
}
void preorderTraversal(bstnode *root)
{
if(root!= NULL)
{
printf("%d\t", root->data);
preorderTraversal(root->left);
preorderTraversal(root->right);
}
}
void inorderTraversal(bstnode *root)
{
if(root != NULL)
{
inorderTraversal(root->left);
printf("%d\t", root->data);
inorderTraversal(root->right);
}
}
void postorderTraversal(bstnode *root){
if(root != NULL)
{
postorderTraversal(root->left);
postorderTraversal(root->right);
printf("%d\t", root->data);
}
}

int height(bstnode *root)
{
int leftheight, rightheight;
// max no. of nodes in a path
if(root==NULL)
return 0;
else
{
leftheight = height(root->left);
rightheight = height(root->right);
if(leftheight > rightheight)
return (leftheight + 1);
else
return (rightheight + 1);

}
}
int totalNodes(bstnode *root)
{
if(root==NULL)
return 0;
else
return(totalNodes(root->left) + totalNodes(root->right) + 1);

}
int totalExternalNodes(bstnode *root)
{
if(root==NULL)
return 0;
else if((root->left==NULL) && (root->right==NULL))
return 1;
else
return (totalExternalNodes(root->left) +
totalExternalNodes(root->right));

}
int totalInternalNodes(bstnode *root)
{
if( (root==NULL) || ((root->left==NULL) && (root->right==NULL)))
return 0;
else
return (totalInternalNodes(root->left)+ totalInternalNodes(root->right) + 1);

}
bstnode *mirrorImage(bstnode *root)
{
struct node *ptr;
if(root!=NULL)
{
mirrorImage(root->left);
mirrorImage(root->right);
ptr=root->left;
ptr->left = ptr->right;
root->right = ptr;
}
}
bstnode *deleteTree(bstnode *root)
{
if(root!=NULL)
{
deleteTree(root->left);
deleteTree(root->right);
free(root);

}
}
