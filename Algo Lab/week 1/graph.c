#include<stdio.h>
#include<stdlib.h>
#define V 5

struct node
{
	int vertex;
	struct node* next;
};
struct graph
{
	int numver;
	struct node **adjLists;
};
struct node* createNode(int v)
{
	struct node* newNode=malloc(sizeof(struct node));
	newNode->vertex=v;
	newNode->next=NULL;
	return newNode;
}

struct graph* createGraph(int vertices)
{
	struct graph* gra=malloc(sizeof(struct graph));
	gra->numver=vertices;
	gra->adjLists=malloc(vertices *sizeof(struct node*));

	int i;
	for(i=0;i<vertices;i++)
		gra->adjLists[i]=NULL;
	return gra;
}
void addEdgeL(struct graph* gra, int src, int dest)
{
	struct node* newNode=createNode(dest);
	newNode->next=gra->adjLists[src];
	gra->adjLists[src]=newNode;

	newNode=createNode(src);
	newNode->next=gra->adjLists[dest];
	gra->adjLists[dest]=newNode;
}
void printGraph(struct graph* gra)
{
	int v;
	for(v=0;v<gra->numver;v++)
	{
		struct node* temp=gra->adjLists[v];
		printf("%d --->",v);
		while(temp)
		{
			if(temp->vertex!=(v))
				printf("%d ",temp->vertex);
			temp=temp->next;
		}
		printf("\n");
	}
}

void init(int arr[][V])
{
	int i,j;
	for(i=0;i<V;i++)
		for(j=0;j<V;j++)
			arr[i][j]=0;
}
void addEdgeM(int arr[][V],int src,int dest)
{
	arr[src][dest]=1;
	arr[dest][src]=1;
}
void printAdjMatrix(int arr[][V],int n)
{
	printf("  ");
	for(int i=0;i<n;i++)
		printf("%d ",i);
	for(int i=0;i<n;i++)
	{
		printf("\n");
		printf("%d ",i);
		for(int j=0;j<n;j++)
			printf("%d ",arr[i][j]);
	}
	printf("\n");
}

int main()
{
	int x,y,numV=0,i=0;
	int adjmatrix[V][V];

	init(adjmatrix);
	struct graph* gra=createGraph(V);
	do
	{
		printf("\n Enter the vertices of the edge: ");
		scanf("%d%d",&x,&y);
		
		addEdgeL(gra,x,y);
		addEdgeM(adjmatrix,x,y);
		printf("Press 1 for another edge!");
		scanf("%d",&x);
	}while(x==1);
	printf("\n Adjacency Matrix \n");
	printAdjMatrix(adjmatrix,V);

	

	printf("\n Adjacency List \n");
	printGraph(gra);


}