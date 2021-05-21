

// finding smallest and largest in pairs
#include<stdio.h>
int main()
{
	
	int a[100],n,k,i,small,large;
	printf("enter number of elements(sum elments):");
	scanf("%d",&n);
	
	small=large=0;
	for(i=0;i<n;i++)
	{
		printf("enter element");
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n;i=i+2)
	{
		if(a[i]<a[i+1])
		{
			if(a[i]<a[small])
			small=i;
			else if(a[i+1]>a[large])
			large=i+1;
		}
		
		else if(a[i]>a[i+1])
		{
			if(a[i]>a[large])
			large=i;
			else if(a[i+1]<a[small])
			small=i+1;
		}
	}
	printf("smallest=%d largest=%d",a[small],a[large]);
	return 0;
	
}
