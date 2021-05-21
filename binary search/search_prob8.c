//checking maximum duplicates range of numbers is 0 to n-1
//problem 8


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
   a[a[i]]+=n;
   
   for(i=1;i<n;i++)
   {
   	if(a[i]>a[max])
   	max=i;
   }
   
   for(i=0;i<n;i++)
   a[i]/=n;
    
   printf(" %d is repeated maximum number of times",a[max]);
   
    return 0;
}

