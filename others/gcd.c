#include<stdio.h>
#include<math.h>

int gcd(int n,int m)
{
	if(n%m==0)
	return m;
	else gcd(m,n%m);
}

int main()
{
	int n,m;
	printf("enter the numbers to find gcd big number should come first:");
	scanf("%d%d",&n,&m);
	
	printf("gcd of %d and %d is %d",n,m,gcd(n,m));
	
}
