

//numberof trailing zeros
#include<stdio.h>

int nooftrailingzero(int n)
{
	int i=0;
	while(n>0)
	{
		n=n/5;
		i=i+n;
	}
	return i;
}

//given no of trailing zeros find the number whose factorial
int revtrailingzeros(int m)
{
int  n=5*m;
 while(m<nooftrailingzero(n))
 {
 	n=n-5;
 }
	
return n;	
}

int main()
{
	int n;
	printf("enter number:");
	scanf("%d",&n);
	printf("m=%d    n=%d",n,revtrailingzeros(n));
}
