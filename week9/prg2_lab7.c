#include <stdio.h>
#include <stdlib.h>
#define MAX 50
typedef struct node
{
    int data;
    struct node *l;
    struct node *r;
} * NODE;
int max(int a, int b) { return (a > b) ? a : b; }
int height(NODE root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->r), height(root->l));
}
void balFactorDis(NODE root)
{
    if (root == NULL)
        return;
    balFactorDis(root->l);
    printf("Balance Factor of Node %d: %d\n", root->data, (height(root->l) - height(root->r)));
    balFactorDis(root->r);
}
/*int balFactor(NODE root)
{
    if (root == NULL)
        return 0;
    balFactor(root->l);
    return (height(root->l) - height(root->r));
    balFactor(root->r);
}*/
void inorder(NODE root)
{
    if (root == NULL)
        return;
    else
    {
        inorder(root->l);
        printf("%d ", root->data);
        inorder(root->r);
    }
}
NODE right(NODE root)
{
    NODE x=root->l;
    NODE t=x->r;
    x->r=root;
    root->l=t;
    return x;
}
NODE left(NODE root)
{
    NODE x=root->r;
    NODE t=x->l;
    x->l=root;
    root->r=t;
    return x;
}
NODE createAVL(NODE root, int x)
{
    NODE n = (NODE)(malloc(sizeof(struct node)));
    n->data = x;
    n->l = NULL;
    n->r = NULL;
    NODE temp = root;
    NODE prev = NULL;
    while (temp != NULL)
    {
        prev = temp;
        if (x < temp->data)
            temp = temp->l;
        else
            temp = temp->r;
    }
    if (x < prev->data)
        prev->l = n;
    else
        prev->r = n;

    temp = root;
    typedef struct
    {
        NODE addr;
        int vis;
    } stack;
    stack arr[MAX];
    int top = -1;
    //ITERATIVE POSTORDER TRAVERSAL
    while (1)
    {
        while (temp)
        {
            arr[++top].addr = temp;
            arr[top].vis = 0;
            temp = temp->l;
        }
        if (arr[top].vis == 1)
        {
            int flag=0;
            prev = arr[top--].addr;
            int bal = height(prev->l)-height(prev->r);
            //Right Rotation
            if (bal > 1 && x < prev->l->data)
            {
                flag=1;
                prev = right(prev);
            }
            //Left Rotation
            else if (bal < -1 && x > prev->r->data)
            {
                flag=1;
                prev = left(prev);
            }
            //LEFT RIGHT
            else if (bal > 1 && x > prev->r->data)
            {
                flag=1;
                prev->l = left(prev->l);
                prev = right(prev);
            }
            //RIGHT LEFT
            else if (bal < -1 && x < prev->r->data)
            {
                flag=1;
                prev->r = right(prev->r);
                prev = left(prev);
            }
            if(flag==1&&top!=-1)
            {
                if(prev->data<(arr[top].addr)->data)
                    (arr[top].addr)->l=prev;
                else
                    (arr[top].addr)->r = prev;
                temp=root;
                top=-1;
                continue;
            }
            if (top==-1)
            {
                root=prev;
                break;
            }
        }
        if (arr[top].vis == 0)
        {
            temp = arr[top].addr;
            temp = temp->r;
            arr[top].vis = 1;
        }
    }
    return root;
}
int main()
{
    int n = 0;
    printf("INPUT THE ELEMENTS [-99 to exit]: ");
    scanf("%d", &n);
    NODE root = (NODE)(malloc(sizeof(struct node)));
    root->data = n;
    root->l = NULL;
    root->r = NULL;
    scanf("%d", &n);
    while (n != -99)
    {
        root = createAVL(root, n);
        scanf("%d", &n);
    }
    printf("INORDER TRAVERSAL: ");
    inorder(root);
    printf("\n");
    printf("\n\t****BALANCE FACTORS****\n");
    balFactorDis(root);
    return 0;
}