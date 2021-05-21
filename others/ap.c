#include<stdio.h>
int main()
{
	int i,sum=0;
	for(i=100;i<=800;i++)
	{
		if(i%7==0)
		{
			printf("%d--",i);
			sum=sum+i;
		}
		
	}
	printf("%d",sum);
	return 0;
} 
