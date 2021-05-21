#include<stdio.h>

void binary(long int a)
{
	if(a<=0)
	return;
	binary(a/2);
	printf("%d",a%2);
}

int main()
{
	long int a[]={1,0,1},b=448,i,n,sum=0;
	binary(b);
	n=sizeof(a)/sizeof(a[0]);
	for(i=0;i<n;i++) 
	sum+=(a[i]*(2^(n-(i-1))));
	//printf("%ld\n",sum);
	
}
