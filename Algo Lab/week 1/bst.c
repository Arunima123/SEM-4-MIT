#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *left;
	struct node *right;
};

typedef struct node BST;
BST *LOC, *PAR;
void search(BST *root, int item)
{
	BST *save,*ptr;
	if(root==NULL)
	{
		LOC=NULL;
		PAR=NULL;
	}
	if(item==root->info)
	{
		LOC=root;
		PAR=NULL;
		return;
	}
	if(item<root->info)
	{
		save=root;
		ptr=root->left;
	}
	else
	{
		save=root;
		ptr=root->right;
	}
	while(ptr!=NULL)
	{
		if(ptr->info==item)
		{
			LOC=ptr;
			PAR=save;
			return;
		}
		if(item<ptr->info)
		{
			save=ptr;
			ptr=ptr->left;
		}
		else
		{
			save=ptr;
			ptr=ptr->right;
		}
	}
	LOC=NULL;
	PAR=save;
	return;
}
struct node *insert(struct node *r, int x)
{
	if(r==NULL)
	{
		r=(struct node*)malloc(sizeof(struct node));
		r->info=x;
		r->left=r->right=NULL;
		return r;
	}
	else if(x<r->info)
		r->left=insert(r->left,x);
	else if(x>r->info)
		r->right=insert(r->right,x);
	return r;
}
void inorder(struct node *t)
{
	if(t==NULL)
	{
		printf(" No elements in a tree to display:");
		return;
	}
	if(t->left !=NULL)
		inorder(t->left);
	printf("%d ", t->info);
	if(t->right !=NULL)
		inorder(t->right);
}
void preorder(struct node *t)
{
	if(t==NULL)
	{
		printf(" No elements in a tree to display:");
		return;
	}
	printf("%d ", t->info);
	if(t->left !=NULL)
		preorder(t->left);
	if(t->right !=NULL)
		preorder(t->right);

}
void postorder(struct node *t)
{
	if(t==NULL)
	{
		printf(" No elements in a tree to display:");
		return;
	}
	if(t->left !=NULL)
		preorder(t->left);
	if(t->right !=NULL)
		preorder(t->right);
	printf("%d ", t->info);

}
int main()
{
	struct node* root=NULL;
	int ele,key;
	char ch;
	do
	{
		printf("\n Enter an element: ");
		scanf("%d",&ele);
		root=insert(root,ele);
		printf("\n Press y or n to insert another element: ");
		scanf(" %c",&ch);
	}while(ch=='y');
	printf("\n Enter the key: ");
	scanf("%d",&key);
	search(root,key);
	if(LOC!=NULL)
		printf("\n %d Found in Binary Search Tree!! \n",key);
	else
	{
		root=insert(root,key);
		printf("\n %d inserted in Binary Search Tree!! \n",key);
	}
	printf("\n Choose a traversal for display! \n 1. Inorder \n 2. Postorder \n 3. Preorder \n");
	scanf("%d",&ele);
	switch(ele)
	{
			case 1: inorder(root);
				    break;
			case 2: postorder(root);
				    break;
			case 3: preorder(root);
				    break;	    
	}
	
}