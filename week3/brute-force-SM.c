#include<stdio.h>
#include<string.h>
#include<time.h>
int main()
{
	int i,j,k,n,m,flag=0;
	int opcount=0;
	char str1[10001],str2[100001];
	clock_t start,end;
	double cpu_time_used;

	for(int i=0;i<10000;i++)
		str1[i]='a';
	str1[10000]='b';

/*	printf("\n Enter text: \n");
	//scanf("%s",str1);
	gets(str1);
	printf("\n Enter pattern: \n");
*/
	scanf("%s",str2);


	n=strlen(str1);
	m=strlen(str2);

	start=clock();
	for(i=0;i<=n-m;i++)
	{
		j=0;
		opcount++;
		while(j<m && str2[j]==str1[j+i])
		{
		
			j++;
			if(j==m)
			{
				flag=1;
				k=i+1;
			}
			else
				flag=0;
		}
	}
	end=clock();
	printf("\n Operation Count: %d\n",opcount);
	printf("\n Size of text: %d",n);
	
	cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
	if(flag==1)
		printf("\n Pattern found at position: %d \n",k);
	else
		printf("\n Pattern not found in text \n ");
	printf("\n %g",cpu_time_used);
}