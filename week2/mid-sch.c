#include<stdio.h>
#include<stdlib.h>

unsigned int MS_GCD(unsigned int m,unsigned int n)
{
	unsigned int t;
	int opcount=0;
	double f=1;

	if(m<n)
		t=m;
	else 
		t=n;

	for(int i=2;i<=m/2;i++)
	{
		opcount++;
		if(m%i==0)
		{
			if(isprime(i))
			{
				if(n%i==0)
				{
					f=f*i;
				}
			}
		}
	}




	return f;

	
	

}

int main()
{
	unsigned int m,n;
	printf("\t Enter the two numbers whose GCD has to be calculated\n");
	scanf("%d",&m);
	scanf("%d",&n);
	printf("\t GCD of two numbers using Middle School method is %d \n",MS_GCD(m,n));
	return 0;
}