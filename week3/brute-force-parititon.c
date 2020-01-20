#include<stdio.h>
#include<stdlib.h>
bool isSubsetsSum(int ar[],int n,int sum)
{
	if(sum=0)
		return true;
	if(n==0 && sum!=0)
		return false;
	if(ar[n-1]>sum)
		return isSubsetsSum(ar,n-1,sum);
	return isSubsetsSum(ar,n-1,sum)|| isSubsetsSum(ar,n-1,sum-ar[n-1]);
}

bool findPartition(int ar[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=ar[i];
	if(sum%2!=0)
		return false;
	return isSubsetsSum(ar,n,sum/2);
}

int main()
{
	int n;
	int ar[30];
	printf("\n Enter size: ");
	scanf("%d",&n);
	printf("\n Enter elements: ");
	for(int i=0;i<n;i++)
		scanf("%d",&ar[i]);
	if(findPartition(ar,n)==true)
		printf("\n Can be partitioned! ");
	else 
		printf("\n Cannot be partitioned! ");
}