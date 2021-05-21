#include<stdio.h>

void maximuminslidingwindow(int *a,int *b,int n,int k)
{
	int i,j,max=-99;
	for(i=0;i<=n-k;i++)
	{
		max=a[i];
		for(j=1;j<k;j++)
		{
			if(max<a[i+j])
			max=a[i+j];
		}
		b[i]=max;
	}
	
}

int main()
{
	int b[100];
	int a[100],n,k,i;
	printf("enter number of elements:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter element");
		scanf("%d",&a[i]);
	}
	printf("thank you\n");
	printf("enter size of window");
	scanf("%d",&k);
	maximuminslidingwindow(a,b,n,k);
	for(i=0;i<=n-k;i++)
	printf("%d\t",b[i]);
	return 0; 
}
