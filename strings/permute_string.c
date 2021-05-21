#include<stdio.h>
#include<string.h>


void swap(char *i,char *j)
{
	char temp;
	temp=*i;
	*i=*j;
	*j=temp;
}

void permute(char *str,int l,int r)
{
	int i;
	
	if(l==r)
	{
	
		printf("%s\n",str);
		return;
    }
	
	for(i=l;i<=r;i++)
	{
		swap(&str[i],&str[l]);//swap
		permute(str,l+1,r);//permute rest
		swap(&str[i],&str[l]);//backtrack
	}
	
}

int main()
{
	char str[100]="abcd";
	permute(str,0,3);
}
