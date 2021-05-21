//catalan number
//with and witjout dp
#include<stdio.h>

int table[1024];

int catalan(int n)
{
	printf("c(%d)\n",n);
	int i,sum=0;
	if(n==0)
	return 1;
	
	for(i=1;i<=n;i++)
	sum+= catalan(n-i)*catalan(i-1);
	
	return sum;
	
}

int fcatalan(int n)
{
	printf("c(%d)\n",n);
	int i,sum=0;
	if(n==0)
	return 1;
	
	for(i=1;i<=n;i++)
	{
		if(table[i-1]==0)
		table[i-1]=fcatalan(i-1);
		
		if(table[n-i]==0)
		table[n-i]=fcatalan(n-i);
	
	sum+= table[n-i]*table[i-1];
    }
	
	return sum;
	
}

int main()
{
	printf("%d",fcatalan(4));
}
