#include<stdio.h>
#include<string.h>

void print_all_n_binary(char *a,int n)
{
	if(n<=0)
	{
	
	
	printf("%s\n",a);
	return;
    }
	a[n-1]='0';
	
	print_all_n_binary(a,n-1);
	a[n-1]='1';
	//printf("%s\n",a);
	print_all_n_binary(a,n-1);
}

int main()
{
	int n;
	char a[3]={'0','0','0'};
	printf("%s\n",a);
	print_all_n_binary(a,3);
	return 0;
}
