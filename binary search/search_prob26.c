// given an array find two numbers whose sum is k
//using sorting
//find 
#include<stdio.h>


void insertionsort(int *a,int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		j=i;
		temp=a[i];
		while(j>=0 && a[j-1]>temp)
		{
		
		a[j]=a[j-1];
		j--;
	    }
	    a[j]=temp;
		
	}
}

int findsumK(int *a,int n,int k)
{
	int i,j;
	i=0;
    j=n-1;
    
    while(i<j)
    {
    	if(a[i]+a[j]==k)
    	{
    		printf("%d and %d are the required numbers",a[i],a[j]);
    		return 1;
		}
		else if(a[i]+a[j]<k)
		i++;
		else
		j--;
	}
	
//	printf("no such numbers");
    
}


int main()
{
    int n,a[1000],i,j,k;
    printf("enter the number of elements");   
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	printf("enter element");
        scanf("%d",&a[i]);
        
    }
    printf("enter the required sum\n");
    scanf("%d",&k);
    
    insertionsort(a,n);
    findsumK(a,n,k);
    
   
    
    //printf("Hello World!\n");
    return 0;
}
