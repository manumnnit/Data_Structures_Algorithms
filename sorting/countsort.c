#include<stdio.h>

int main()
{
   int a[100],b[100],c[100],n,k,i;
   
   printf("enter number of elements");
   scanf("%d",&n);
   printf("enter the range of integers");
   scanf("%d",&k);
   for(i=0;i<n;i++)
   {
   	printf("enter element:");
   	scanf("%d",&a[i]);
   }
   
   printf("array before sorting");
   for(i=0;i<n;i++)
   {
   	//printf("enter element:");
   	printf("%d\n",a[i]);
   }
   
   for(i=0;i<=k;i++)
   c[i]=0;
   
   for(i=0;i<n;i++)
   c[a[i]]=c[a[i]]+1;
   
   for(i=1;i<=k;i++)
   c[i]=c[i-1]+c[i];
   
   for(i=0;i<n;i++)
   {
   	b[c[a[i]]]=a[i];
   	c[a[i]]--;
   }
   
   printf("array after sorting");
   for(i=1;i<=n;i++)
   {
   	//printf("enter element:");
   	printf("%d\n",b[i]);
   }
   
    //printf("Hello World!\n");
    return 0;
    
    
    
    
    
    
    
    
    
}


