//finding first repeated element
//problem 9 may use hashing 
//here brute force is implemented


#include<stdio.h>

int main()
{
    int n,a[100],i,j,max=0;
    
    printf("enter the number of elements");   
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	printf("enter element in the range of 0-%d\n",n-1);
        scanf("%d",&a[i]);
        
    }
   
   
   for(i=0;i<n;i++)
   {
   	for(j=i+1;j<n;j++)
   	{
   		if(a[i]==a[j])
   		{
   			printf("first repeated element is %d",a[i]);
   			return;
		   }
	   }
   }
    
   printf("NO duplicates");
   
    return 0;
}

