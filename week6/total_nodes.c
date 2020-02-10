#include <stdio.h>

#include <stdlib.h>

int opcount=0;

struct node

{

    int info;

    struct node *left, *right;

};

/*struct node *createnode(int key)

{

    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    newnode->info = key;

    newnode->left = NULL;

    newnode->right = NULL;

    return(newnode);

}
*/

struct node *create()
{
    struct node *p;
    
    int x;
    
    printf("Enter data(-1 for no node):");
    
    scanf("%d",&x);

    if(x==-1)
    return NULL;

    p=(struct node*)malloc(sizeof(struct node));
    
    p->info=x;
    
    printf("Enter left child of %d:\n",x);
    
    p->left=create();
    
    printf("Enter right child of %d:\n",x);
    
    p->right=create();
    
    return p;
}

static int count = 0;

int countnodes(struct node *root)

{

    if(root != NULL)

    {

        opcount++;
        countnodes(root->left);

        count++;

        countnodes(root->right);

    }

    return count;

}

/*

 * Main Function

 */

int main()

{

    /* Creating first Tree. */

    //struct node *newnode = createnode();
    struct node *newnode=create();


    printf("Number of nodes in tree 1 = %d ",countnodes(newnode));
    printf("\nOpcount: %d",opcount);
}