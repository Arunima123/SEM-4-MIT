#include<stdio.h>
#include<stdlib.h>

unsigned int E_GCD(unsigned int m,unsigned int n)
{
	unsigned int r;
	int opcount=0;

	while(n!=0)
	{
		opcount++;
		r=m%n;
		m=n;
		n=r;
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
	printf("\t GCD of two numbers using Euclids method is %d \n",E_GCD(m,n));
	return 0;
}