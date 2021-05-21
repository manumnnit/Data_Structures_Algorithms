

#include<stdio.h>


void merge(int *a,int *t,int left,int mid,int right)
{
	int lstart,lend,rstart,rend,temp_pos,size,i;
	lstart=left;
	lend=mid-1;
	rstart=mid;
	rend=right;
	temp_pos=left;
	size=right-left+1;
	while((lstart<=lend) && (rstart<=rend))
	{
		if(a[lstart]<=a[rstart])
		{
		t[temp_pos]=a[lstart];
		temp_pos++;
		lstart++;
		}
		else
		{
			t[temp_pos]=a[rstart];
			temp_pos++;
		     rstart++;
		}
	}
	            while(lstart<=lend){
		             t[temp_pos]=a[lstart];
		            temp_pos++;
		             lstart++;
                  	}
                 	while(rstart<=rend)
	                  {
	                  	t[temp_pos]=a[rstart];
		                  	temp_pos++;
		                    rstart++;
                       	} 
						   
						     
						   
			for(i=0;i<=size;i++)
			{
				a[right]=t[right];
				right--;
	     	}
}


void mergesort(int *a,int *t,int left,int right)
{  int mid;
	if(right>left)
	{
		mid=(left+right)/2;
		mergesort(a,t,left,mid);
		mergesort(a,t,mid+1,right);
		merge(a,t,left,mid+1,right);
	}
}

int main()
{
    int n,a[100],i,t[100];
    printf("enter the number of elements");   
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	printf("enter element");
        scanf("%d",&a[i]);
        
    }
    
    mergesort(a,t,0,n-1);
    for(i=0;i<n;i++)
    { 
    	//printf("enter element");
        printf("%d\n",a[i]);
        
    }
    
    //printf("Hello World!\n");
    return 0;
}
