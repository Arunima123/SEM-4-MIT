#include<stdio.h>
#include<stdlib.h>

unsigned int CIC_GCD(unsigned int m,unsigned int n)
{
	unsigned int t;
	int opcount=0;

	if(m<n)
		t=m;
	else
		t=n;

	while(t!=0)
	{
		opcount++;
		if(m%t==0)
		{
			if(n%t==0)
			{
				
				printf("Operation count= %d\n",opcount);
				return t;
			}
			t-=1;
		}
		else
			t-=1;
	}
	printf("Operation count= %d\n",opcount);
	return m;
	

}

int main()
{
	unsigned int m,n;
	printf("\t Enter the two numbers whose GCD has to be calculated\n");
	scanf("%d",&m);
	scanf("%d",&n);
	printf("\t GCD of two numbers using Consecutive Integer Checking method is %d \n",CIC_GCD(m,n));
	return 0;
}