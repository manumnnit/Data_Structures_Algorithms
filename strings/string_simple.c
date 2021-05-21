#include<stdio.h>
#include<string.h>
#include<malloc.h>

//note: you can return local array address from a function one way is to use malloc or static(but it persists for program)

void reverse(char *str)
{
	int i,j;
	char temp;
	i=0;
	j=strlen(str)-1;
	
	while(i<j)
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
		i++;
		j--;
	}
return;	
}

char* substr(char *str,int p,int len)
{
	char *temp=malloc((sizeof(char)*len)+1);
	int i,j;
	i=p;
	for(j=0;j<len;j++,i++)
	temp[j]=str[i];
	temp[j]='\0';
	//printf("%s\n",temp);
	return temp;
}

int main()
{
	char str[]="hello";

	char *p=substr(str,1,3);
	
	printf("%s",p);
}
