#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void bubbleSort(int *a,unsigned int n)
{
	unsigned int i,j;
	int temp;
	int opcount=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			opcount++;
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("\n Operation Count %d \n",opcount);
}
int main()
{
	clock_t start,end;
	double cpu_time_used;
	int *a;
	int i,n;
	printf("\n Enter the number of elements: \n");
	scanf("%d",&n);
	printf("\n Enter elements: ");
	a=(int *)malloc(sizeof(int)*n);
	for(int j=0;j<n;j++)
		scanf("%d",&a[j]);
	start=clock();
	bubbleSort(a,n);
	end=clock();
	for(i=0;i<n;i++)
		printf("\n%d",a[i]);
	cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n %g",cpu_time_used);
	free(a);
}