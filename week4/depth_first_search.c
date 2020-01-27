#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5
struct Vertex{
	char label;
	bool visited;
};

int stack[MAX];
int top=-1;
int x=0,y=0;

struct Vertex* lstVertices[MAX];

int adjMatrix[MAX][MAX];

int vertexCount=0;

int pushar[100];
int popar[100];

void push(int item)
{
	stack[++top]=item;
	pushar[x++]=item;
}

int pop()
{
	popar[y++]=stack[top];
	return stack[top--];
}

int peek()
{
	return stack[top];
}

bool isStackEmpty()
{
	return top==-1; 
}

void addVertex(char label)
{
	struct Vertex* vertex=(struct Vertex*)malloc(sizeof(struct Vertex));
	vertex->label=label;
	vertex->visited=false;
	lstVertices[vertexCount++]=vertex;
}

void addEdge(int start,int end)
{
	adjMatrix[start][end]=1;
	adjMatrix[end][start]=1;
}

void displayVertex(int vertexIndex)
{
	printf("%c",lstVertices[vertexIndex]->label);
}

int getAdjUnvisitedVertex(int vertexIndex)
{
	int i;
	for(i=0;i<vertexCount;i++)
		if(adjMatrix[vertexIndex][i]==1 && lstVertices[i]->visited==false)
		{
			return i;
		}
	return -1;
}

void depthFirstSearch()
{
	int i;

	lstVertices[0]->visited=true;
	displayVertex(0);
	push(0);

	while(!isStackEmpty())
	{
		int unvisitedVertex=getAdjUnvisitedVertex(peek());
		if(unvisitedVertex==-1)
			pop();
		else
		{
			lstVertices[unvisitedVertex]->visited=true;
			displayVertex(unvisitedVertex);
			push(unvisitedVertex);
		}
	}

	for(i=0;i<vertexCount;i++)
		lstVertices[i]->visited=false;
}

int main()
{
	int i,j;
	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++)
			adjMatrix[i][j]=0;

	int n,m;
	char ver;

	
	printf("\n Enter the number of vertices: ");
	scanf("%d",&n);
	printf("\n Enter the vertices: ");
	for(i=0;i<n;i++)
	{
		scanf(" %c",&ver);
		addVertex(ver);
	}

	do
	{
		printf("\n Enter an edge: ");
		scanf("%d%d",&n,&m);
		addEdge(n,m);
		printf("\n Press 1 for another edge!");
		scanf("%d",&n);
	}while(n==1);



/*
   addVertex('S');   // 0
   addVertex('A');   // 1
   addVertex('B');   // 2
   addVertex('C');   // 3
   addVertex('D');   // 4

   addEdge(0, 1);    // S - A
   addEdge(0, 2);    // S - B
   addEdge(0, 3);    // S - C
   addEdge(1, 4);    // A - D
   addEdge(2, 4);    // B - D
   addEdge(3, 4);    // C - D
*/
   printf("Depth First Search: ");
   depthFirstSearch(); 

   printf("\n Push order of vertices: ");
   for(i=0;i<x;i++)
   	printf("%d ",pushar[i]);

   printf("\n Pop order of vertices: ");
   for(i=0;i<y;i++)
   	printf("%d ",popar[i]);

   return 0;   
}


