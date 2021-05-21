#include <stdio.h>

void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int partition(int *a,int p,int q)
{
    int i,j,pivot;
    
    i=p;
    pivot=a[p];
    j=i+1;
    while(j<=q)
    {
        if(a[j]<pivot)
        {
            i=i+1;
            swap(&a[i],&a[j]);
        }
        j++;
    }
    swap(&a[p],&a[i]);
    return i;
    
}
void quicksort(int *a,int p,int q)
{
    int m;
    if(p<=q)
    {
	
    m=partition(a,p,q);
    quicksort(a,p,m-1);
    quicksort(a,m+1,q);
   }
    
}

void bubblesort(int *a,int n)
{
	int i,j,flag=1;
	
	for(i=0;i<n-1  && flag;i++)
	{
		flag=0;
		for(j=0;j<n-i-1;j++)
		if(a[j]>a[j+1])
		{
		
		swap(&a[j],&a[j+1]);
		flag=1;
	    }
	}
}

void selectionsort(int *a,int n)
{
	int i,j,min;
	
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			min=j;
		}
		swap(&a[i],&a[min]);
	}
}

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

void shellsort(int *a,int n)
{
	int i,j,temp,gap;
	for(gap=n/2;gap>0;gap/=2)
	{
	
        	for(i=gap;i<n;i++)
         	{
		         j=i;
	        	temp=a[i];
	      	while(j>=gap && a[j-gap]>temp)
		     {
		
		      a[j]=a[j-gap];
		        j-=gap;
	         }
	         a[j]=temp;
		
	}
  }
}

void merge(int *a,int *t,int left,int mid,int right)
{
	int lstart,lend,rstart,rend,temp_pos;
	lstart=left;
	lend=mid;
	rstart=mid+1;
	rend=right;
	temp_pos;
	while(lstart<=lend && rstart<=rend)
	{
		if(a[lstart]<a[rstart])
		{t[temp_pos]=a[lstart];
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
						   
			while(right>=left)
			{
				a[right]=t[right];
				right--;
	     	}
}


void mergesort(int *a,int *t,int left,int right)
{  int mid;
	if(left<right)
	{
		mid=(left+right)/2;
		mergesort(a,t,left,mid);
		mergesort(a,t,mid+1,right);
		merge(a,t,left,mid,right);
	}
}


int main()
{
    int n,a[1000],i,t[1000];
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

