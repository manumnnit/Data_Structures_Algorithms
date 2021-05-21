//checking is sqaure

#include<stdio.h>

int issqaure(int a)
{
	if(a<=0)
	return 0;
	int i=1;
	while((i*i)<a)
	i++;
	if(a==(i*i))
	return 1;
	else
	return 0;
}


int main()
{
	int a=1;
	if(issqaure(a))
	printf("yes\n");
	else 
	printf("no\n");
}
