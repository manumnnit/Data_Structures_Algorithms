//finding number occuring odd number of times using xor operation
//problem 18



#include<stdio.h>

int main()
{
    int n,a[100],x,i;    
    printf("enter the number of elements");   
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	printf("enter element\n");
        scanf("%d",&a[i]);
        
    }
    
    for(i=0;i<n;i++)
    x^=a[i];
    
    
    
    printf("the  number is %d",x);
   
   
   
   
    return 0;
}

