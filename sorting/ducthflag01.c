#include<stdio.h>

int main()
{
    int n,a[100],i,j;
    
    printf("enter the number of elements");   
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	printf("enter element in the range of 0-1\n");
        scanf("%d",&a[i]);
        
    }
    
    i=0;j=n-1;
    while(i<j)
    {
    	while(i<j && a[i]==0)
    	i++;
    	while(i<j && a[j]==1)
    	j--;
    	a[i]=0;
    	a[j]=1;
    	i++;
    	j--;
	}
    
    for(i=0;i<n;i++)
    printf("%d",a[i]);
   
 return 0;  
}
