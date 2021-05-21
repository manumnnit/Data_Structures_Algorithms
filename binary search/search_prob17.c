//finding the missing number using xor operation
//problem 17
//numbers from 0 to n-1 1 number is missing
//no number is repeated


#include<stdio.h>

int main()
{
    int n,a[100],x,i;    
    printf("enter the number of elements");   
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	printf("enter element in the range of 0-%d\n",n-1);
        scanf("%d",&a[i]);
        
    }
    
    for(i=0;i<n-1;i++)
    x^=a[i];
    
    for(i=0;i<n;i++)
    x^=i;
    
    printf("the missing number is %d",x);
   
   
   
   
    return 0;
}

