//finding k smallest elemnts in the array using partition algorithm


// complexity nlogk
#include<stdio.h>

void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

int partition(int *a,int p,int q)

{
	int i,j,m,pivot;
	if(p==q)
	return p;
	i=p;j=i+1;
	pivot=a[p];
   while(j<=q)
   {
   	if(a[j]<pivot)
   	{
   		i++;
   		swap(&a[i],&a[j]);
	   }
   	j++;
   }
   swap(&a[p],&a[i]);
   return i;
	
}

void printk(int *a,int p,int q,int k)
{
	int m,i;
	if(p<q )
	{
		m=partition(a,p,q);
		if(m==k)
		{
			printf("output-");
			for(i=0;i<k;i++)
			printf("%d\n",a[i]);
		}
		else if(m<k)
		printk(a,m+1,q,k);
		else printk(a,p,m-1,k);
	}
}
int main()
{
	
	int a[100],n,k,i,m;
	printf("enter number of elements(sum elments):");
	scanf("%d",&n);
	printf("enter k =");
	scanf("%d",&k);
	
	for(i=0;i<n;i++)
	{
		printf("enter element");
		scanf("%d",&a[i]);
	}
	printk(a,0,n-1,k);
	

	return 0;
	
}
