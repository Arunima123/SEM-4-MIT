#include<stdio.h>
#include<string.h>

#define MAX 500
int t[MAX];
int s=0,us=0;
void shifttable(char p[])
{
 int i,j,m;
 m=strlen(p);
 for(i=0;i<MAX;i++)
  t[i]=m;
 for(j=0;j<m-1;j++)
  t[p[j]]=m-1-j;
}
int horspool(char src[],char p[])
{
 int i,j,k,m,n;
 n=strlen(src);
 m=strlen(p);
 printf("\n Length of text= %d ",n);
 printf("\n Length of pattern= %d ",m);
 i=m-1;
 while(i<n)
 {
  k=0;
  while((k<m)&&(p[m-1-k]==src[i-k]))
   k++;
 //printf("%d ",k);
  if(k==m)
   {
      s=m;
      return(i-m+1);
   }
  else
  {  
   i+=t[src[i]];
   us+=(k+1);
  }
 }
 return -1;
}
void main()
{
 char src[100],p[100];
 int pos;
 printf("\n Enter the text in which pattern is to be searched: ");
 gets(src);
 printf("\n Enter the pattern to be searched: ");
 gets(p);
 shifttable(p);
 pos=horspool(src,p);
  if(pos>=0)
    printf("\n The desired pattern was found starting from position %d ",pos+1);
  else
    printf("\n The pattern was not found in the given text!");

  printf("\n Key comparisons in successful search: %d",s);
  printf("\n Key comparisons in unsuccessful search: %d",us);
}