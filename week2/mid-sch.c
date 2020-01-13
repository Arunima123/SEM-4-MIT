#include<stdio.h>
#include<stdlib.h>

unsigned int MS_GCD(unsigned int m,unsigned int n)
{
	unsigned int d=2;
	int opcount=0;
	double f=1;

	if(m>n)
	{
		m=m+n;
		n=m-n;
		m=m-n;

	}
	while(m!=1)
	{
		opcount++;
		if(m%d==0)
		{
			m=m/d;
			if(n%d==0)
			{
				n=n/d;
				f=f*d;
			}
		}
		else
			d++;
	
	}

	printf("Operation count= %d\n",opcount);
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