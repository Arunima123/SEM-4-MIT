#include<stdio.h>
#include<stdlib.h>
int a[100],b[100],c[100],d[100],w,n,y=0;
int min=0;
void cal(int a[],int b[],int c[],int size,int n);
int main()
{
	printf("Enter the knapsack capacity: ");
	scanf("%d",&w);
	printf("\n Enter the size: ");
	scanf("%d",&n);
	printf("\n Enter the items,corresponding values and corresponding weights: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		scanf("%d",&b[i]);
		scanf("%d",&c[i]);
	}
	cal(a,b,c,n,n);
	printf("\n knapsack value: %d",min);
	printf("\n List: ");
	for(int i=0;i<=y;i++)
		printf(" %d ",d[i]);
}
static int max=0;

void cal(int a[],int b[],int c[],int size,int n)
{
	//printf("\n here");
	int sum=0,sum2=0,e[100];
	if(size==1)
	{
		return;
	}
	for(int i=0;i<n;i++)
	{
		sum=0;
		sum2=0;
		for(int k=0;k<y;k++)
			e[i]=0;
		y=0;
		for(int j=i;j<n;j++)
		{
			sum+=c[j];
			sum2+=b[j];
			e[y++]=a[j];
			if(sum<=w && sum>=max && min<=sum2)
			{
				max=sum;
				min=sum2;
				for(int i=0;i<y;i++)
					d[i]=e[i];
			}
		}
	}
	cal(a,b,c,size-1,n);	
}