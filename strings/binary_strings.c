#include<stdio.h>

char a[4]={'0','0','0','\0'};

void binary(int n)
{
	if(n<1)
	
	printf("%s\n",a);
	
	else{
		a[n-1]='0';
		binary(n-1);
		a[n-1]='1';
		binary(n-1);
	}
}

int main()
{
	binary(4);
	return 0;
}
