#include<stdio.h>
#include<math.h>

int isprime (int n)
{
	int i=2;
	while(i<=sqrt(n))
	{
		if(n%i==0)
		return 1;
		i++;
	}
}

int main()
{
	int n;
	printf("enter the number to check weather it is prime:");
	scanf("%d",&n);
	if(isprime(n))
	printf("%d is prime",n);
	else
	printf("%d is  not prime",n);
}
