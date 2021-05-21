//checking duplicates using negation method


#include<stdio.h>

int main()
{
    int n,a[100],i,j,count=0;
    
    printf("enter the number of elements");   
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	printf("enter element in the range of 0-%d\n",n-1);
        scanf("%d",&a[i]);
        
    }
   
   
    for(i=0;i<n;i++)
    {
    	if(a[a[i]]<0)
    	{
    		printf("duplicates exist %d\n",a[i]);
    		break;
		}
		else if(a[i]==0){
			count++;
			if(count>1)
			{printf("duplicates exist\n");
    		break;
			}
		}
		a[a[i]]=0-a[a[i]];
	}
   if(i==n)
   printf("no duplicates\n");
    
   
   
    return 0;
}

