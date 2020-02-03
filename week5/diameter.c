#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left,*right;
};

struct node* newNode(int data);

int max(int a,int b);

int height(struct node* node);

int diameter(struct node *tree)
{
	if(tree==NULL)
		return 0;

	int lheight=height(tree->left);
	int rheight=height(tree->right);

	int ldiameter=diameter(tree->left);
	int rdiameter=diameter(tree->right);

	return max(lheight + rheight + 1, max(ldiameter, rdiameter)); 
	
}
int height(struct node* node) 
{ 
   /* base case tree is empty */ 
   if(node == NULL) 
       return 0; 
  
   /* If tree is not empty then height = 1 + max of left  
      height and right heights */    
   return 1 + max(height(node->left), height(node->right)); 
}  
  
/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct node* newNode(int data) 
{ 
  struct node* node = (struct node*) 
                       malloc(sizeof(struct node)); 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  
  return(node); 
} 
  
/* returns maximum of two integers */
int max(int a, int b) 
{ 
  return (a >= b)? a: b; 
}     
  
/* Driver program to test above functions*/
struct node *create()
{
    struct node *p;
    int x;
    printf("Enter data(-1 for no node):");
    scanf("%d",&x);

    if(x==-1)
	return NULL;

    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    printf("Enter left child of %d:\n",x);
    p->left=create();
    printf("Enter right child of %d:\n",x);
    p->right=create();
    return p;
}

int main() 
{ 
 
 /* int n;
  printf("Enter the root node: ");
  scanf("%d",&n);
  struct node *root = newNode(1); 
  
  do{
  	printf("press 1 for left and 2 for right node: ");
  	scanf("%d",&n);
  	switch(n)
  	{
  		case 1: 
  	}

 
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  root->left->left  = newNode(4); 
  root->left->right = newNode(5); 
  */
  struct node *root=create();
  printf("Diameter of the given binary tree is %d\n", diameter(root)); 
  
  getchar(); 
  return 0; 
} 
