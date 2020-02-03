#include<stdio.h>

int a[20][20],reach[20],n;
void dfs(int v)
{
	int i;
	reach[v]=1;
	for(i=0;i<n;i++)
		if(a[v][i] && !reach[i])
			dfs(i);
}

int main()
{
	int i,j,count,origin,destin,max_edge;

	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		reach[i]=0;
		for(j=0;j<n;j++)
			a[i][j]=0;
	}

	printf("\n Enter the Adjacency Matrix\n");

	/*for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			printf("\n Enter connection between vertex %c and vertex %c ",i+65,j+65);
			scanf("%d",&a[i][j]);
		}
	*/
	max_edge = n*(n-1);
 
	for(count=1; count<=max_edge; count++)
	{
		printf("Enter edge %d( -1 -1 to quit ) : ",count);
		scanf("%d %d",&origin,&destin);

		if((origin == -1) && (destin == -1))
			break;
 
		if(origin>=n || destin>=n || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			count--;
		}
		else
		{
			a[origin][destin] = 1;
			a[destin][origin] =1;
		}

		//a[origin][destin]=1;
	}
 
	dfs(0);
	printf("\n Pop out order: ");
	for(i=n-1;i>=0;i--)
	{
		if(reach[i])
			printf("%d\t",i);
	}

	for(i=n-1;i>=0;i--)
	{
		if(reach[i]==0)
			printf("\n%d",i);
	}
	return 0;
}