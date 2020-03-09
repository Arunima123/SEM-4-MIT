#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define htlf 13
#define ecell "EMPTY_CELL"
typedef struct node
{
    char key[50];
    int pos;
}*HASH;
int c=0;
int close_hashfnc(char str[])
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
void search_hash(HASH arr[],char str[],int k)
{
    int i=k;
    while((i+1)!=k)
    {
        if(strcmp(arr[i]->key,str)==0)
        {
            printf("FOUND AT POSITION: %d\n",arr[i]->pos);
            c=1;
        }
        i=(i+1)%htlf;
    }
    if(strcmp(arr[i]->key,str)==0)
    {
        printf("FOUND AT POSITION: %d\n",arr[i]->pos);
        c=1;
    }
}
void delete(HASH arr[])
{
    for(int i=0;i<htlf;i++)
    {
        arr[i]=(HASH)(malloc(sizeof(struct node)));
        strcpy(arr[i]->key,ecell);
        arr[i]->pos=-1;
    }
}
void create_hash(HASH arr[],int key,char str[],char patt[],int p)
{
    if(strcmp(arr[key]->key,ecell)==0)
    {
        strcpy(arr[key]->key,str);
        arr[key]->pos=p;
        return;
    }
    int i=key;
    while(1)
    {
        key=(key+1)%htlf;
        if(strcmp(arr[key]->key,ecell)==0)
        {
            strcpy(arr[key]->key,str);
            arr[key]->pos=p;
            return;
        }
        else if(i==key)
        {
            search_hash(arr,patt,close_hashfnc(patt));
            delete(arr);
        }
        else
        {
            continue;
        }
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
    HASH arr[htlf];
    for(i=0;i<htlf;i++)
    {
        arr[i]=(HASH)(malloc(sizeof(struct node)));
        strcpy(arr[i]->key,ecell);
        arr[i]->pos=-1;
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
        int key=close_hashfnc(temp);
        create_hash(arr,key,temp,patt,i);
    }
    int k=close_hashfnc(patt);
    search_hash(arr,patt,k);
    if(c==0)
    {
        printf("Not Found\n");
    }
    return 0;
}