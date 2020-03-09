#include<stdio.h>
#include<stdlib.h>
#define MAX_INT 99999
void display(int heap[],int n)
{
    for(int i=1;i<=n;i++)
        printf("%d ",heap[i]);
    printf("\n");
}
void make_heap(int arr[], int n)  
{  
    for (int i = 1; i<=n; i++)  
    {
        if (arr[i] > arr[i / 2])  
        { 
            int j = i; 
            while (arr[j] > arr[j / 2])  
            { 
                //swap(arr[j], arr[(j / 2]);
                int t=arr[j];
                arr[j]=arr[j/2];
                arr[j/2]=t; 
                j = j / 2; 
            } 
        }  
        if (arr[i] > arr[(i - 1) / 2])  
        { 
            int j = i; 
            while (arr[j] > arr[(j - 1) / 2])  
            { 
                //swap(arr[j], arr[(j - 1) / 2]);
                int t=arr[j];
                arr[j]=arr[(j-1)/2];
                arr[(j-1)/2]=t; 
                j = (j - 1) / 2;
            } 
        }
    } 
} 
/*void make_heap(int heap[],int n)
{
    for(int i=n/2;i>=1;i--)
    {
        int k=i;
        int v=heap[k];
        int bool=0;
        while(!bool && 2*k<=n)
        {
            int j=2*k;
            if(j<n)
            {
                if(heap[j]<heap[j+1])
                    j=j+1;
            }
            if(v>=heap[j])
                bool=1;
            else 
            {
                heap[k]=heap[j];
                k=j;
            }
        }
        heap[k]=v;
    }
}*/
int main()
{
    int heap[50];
    heap[0]=MAX_INT;
    int n;
    printf("Input the number of elements: ");
    scanf("%d",&n);
    printf("Input the elements: ");
    for(int i=1;i<=n;i++)
        scanf("%d",&heap[i]);
    printf("\nORIGINAL ORDER: ");
    display(heap,n);
    make_heap(heap,n);
    printf("\nHEAP ORDER: ");
    display(heap,n);
    return 0;
}