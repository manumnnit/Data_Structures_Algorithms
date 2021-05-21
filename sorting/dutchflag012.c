#include<stdio.h>

void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

int main()
{
    int n,a[100],i,j,mid;
    
    printf("enter the number of elements");   
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	printf("enter element in the range of 0-2\n");
        scanf("%d",&a[i]);
        
    }
    
    i=0;j=n-1,mid=0;
    
    
    
    
		
		while(mid<=j)
		{
		
    	switch(a[mid])
    	{
    		case 0:swap(&a[i],&a[mid]);
    		i++;
    		mid++;
    		break;
    		
    		case 1:mid++;
    		break;
    		
    		case 2:swap(&a[mid],&a[j]);
    	
    		j--;
    		break;
		}
	}
    
    for(i=0;i<n;i++)
    printf("%d",a[i]);
   
 return 0;  
}
