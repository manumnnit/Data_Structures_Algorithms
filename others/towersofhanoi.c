#include<stdio.h>

void toh(char l, char m,char r,int n)
{
	if(n==0) return;
	toh(l,r,m,n-1);
	printf("%c-%c\n",l,r);
	toh(m,l,r,n-1);
	
}

int main()
{
	int n;
	char l='l',m='m',r='r';
	printf("enter the number of towers:");
	scanf("%d",&n);
	toh(l,m,r,n);
	return 0;
}
