#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node *left,*right;
	int height;
	int fac;
}NODE;

int max(int a,int b)
{
	return (a>b)?a:b;
}

int height(NODE *N)
{
	if(N==NULL)
		return 0;
	return N->height;
}

int getBalance(NODE *N)
{
	if(N==NULL)
		return 0;
	return height(N->left)-height(N->right);
}

NODE* create(NODE *bnode,int x)
{
	NODE *getnode;
	if(bnode==NULL)
	{
		bnode=(NODE*)malloc(sizeof(NODE));
		bnode->info=x;
		bnode->left=bnode->right=NULL;
		bnode->height=1;
	}
	else if(x>bnode->info)
		bnode->right=create(bnode->right,x);
	else if(x<bnode->info)
		bnode->left=create(bnode->left,x);
	else
	{
		printf("Duplicate node\n");
		exit(0);
	}
	
	bnode->height=1+max(height(bnode->left),height(bnode->right));

	bnode->fac=getBalance(bnode);

	return(bnode);


}

void inorder(NODE *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		printf(" %d,%d ",ptr->info,ptr->fac);
		inorder(ptr->right);
	}
}
3
void main()
{
	int n,x,ch,i;
	NODE *root;
	root=NULL;
	while(1)
	{
		printf(" 1. Insert\n 2. Balance Factor\n 3. Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter node:\n");
					scanf("%d",&x);
					root=create(root,x);
					break;
			case 2: //printf("\n Inorder traversal:\n");
					inorder(root);
					
				//	printf("\n Preorder traversal:\n");
				//	preorder(root);
					/*printf("\n Postorder traversal:\n");
					postorder(root);
					*/
					break;
			case 3: exit(0);
		}
	}
}