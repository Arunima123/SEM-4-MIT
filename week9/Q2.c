#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define htlf 20
typedef struct node
{
    char key[50];
    int pos;
    struct node* next;
}*HASH;
typedef struct harr
{
    struct node* next;
}*HASHTABLE;
HASHTABLE create_hash(HASHTABLE arr[],int key,char str[],int p)
{
    HASH n=(HASH)(malloc(sizeof(struct node)));
    strcpy(n->key,str);
    n->pos=p;
    n->next=NULL;
    if(arr[key]->next==NULL)
    {
        arr[key]->next=n;
        return arr[key];
    }
    HASH root=arr[key]->next;
    while(root->next!=NULL)
    {
        root=root->next;
    }
    root->next=n;
    return arr[key];
}
int open_hashfnc(char str[])
{
    int i=0;
    int sum=0;
    while(str[i]!='\0')
    {
        sum+=(int)str[i];
        i++;
    }
    return (sum%htlf);
}
void search_hash(HASH root,char patt[])
{
    if(root==NULL)
    {
        printf("NOT FOUND\n");
        return;
    }
    int c=0;
    while(root)
    {
        if(strcmp(root->key,patt)==0)
        {
            printf("FOUND AT POSITION: %d\n",root->pos);
            c=1;
        }
        root=root->next;
    }
    if(c==0)
    {
        printf("NOT FOUND\n");
    }
}
int main()
{
    char str[50];
    char patt[50];
    int i;
    printf("Input the String: ");
    fgets(str,49,stdin);
    printf("Input the Pattern: ");
    fgets(patt,49,stdin);
    str[strlen(str)-1]='\0';
    patt[strlen(patt)-1]='\0';
    printf("The String: %s\n",str);
    printf("The Pattern: %s\n",patt);
    HASHTABLE arr[htlf];
    for(i=0;i<htlf;i++)
    {
        arr[i]=(HASHTABLE)(malloc(sizeof(struct harr)));
        arr[i]->next=NULL;
    }
    int m=strlen(str);
    int n=strlen(patt);
    for(i=0;i<=m-n;i++)
    {
        char temp[50];
        int j=0;
        while(j<n)
        {
            temp[j]=str[i+j];
            j++;
        }
        temp[j]='\0';
        int key=open_hashfnc(temp);
        arr[key]=create_hash(arr,key,temp,i);
    }
    int k=open_hashfnc(patt);
    search_hash(arr[k]->next,patt);
    return 0;
}