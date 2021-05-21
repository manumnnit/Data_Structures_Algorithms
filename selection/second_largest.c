

// finding second largest in array
#include<stdio.h>

int second_largetst_brute_force(int *a,int n)

{
	int prev,i,max;
	if(n==1)
	return -99;
	prev=-99;max=a[0];
	for(i=1;i<n;i++)
	{
      	if(a[i]>max)
	    {prev=max;
		max=a[i];
		}
	else if(a[i]>prev)
		prev=a[i];	
	}
	return prev;
	
}
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
	
	printf("%d",second_largetst_brute_force(a,n));
	return 0;
	
}
