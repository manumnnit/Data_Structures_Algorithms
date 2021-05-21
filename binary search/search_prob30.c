//problem 30
//two elements whose sum is closest to zero

#include<stdio.h>
#include<math.h>
#include<limits.h>

void insertionsort(int *a,int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		j=i;
		temp=a[i];
		while(j>0 && a[j-1]>temp)
		{
		
		a[j]=a[j-1];
		j--;
	    }
	    a[j]=temp;
		
	}
}

int main()
{
    int n,a[1000],i,j,k,closestpositivesum=INT_MAX,closestnegativesum=INT_MIN,answer;
    printf("enter the number of elements");   
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	printf("enter element");
        scanf("%d",&a[i]);
        
    }
   
    insertionsort(a,n);
    for(i=0;i<n;i++)
    printf("%d--\n",a[i]);
    i=0;j=n-1;
    while(i<j)
    {
    	k=a[i]+a[j];
    	if(k>0)
    	{
    		if(k<closestpositivesum)
    		closestpositivesum=k;
    		j--;
		}
		
		else if(k<0)
    	{
    		if(k>closestnegativesum)
    		closestnegativesum=k;
    		i++;
		}
		
		else{
			printf("closest sum is %d",a[i]+a[j]);
			return;
		}
    	
	}
    
   answer=abs(closestnegativesum)<abs(closestpositivesum)?closestnegativesum:closestpositivesum;
   
    printf("closest sum is %d",answer);
    //printf("Hello World!\n");
    return 0;
}
