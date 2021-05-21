#include<stdio.h>
#include<string.h>

int main()
{
	char str[50];
	int i=0,j=-1,len;
	printf("enter the string les than 50 chars please!!\n");
	scanf("%s",str);
	
	len=strlen(str);
	//printf("%s\n",str);
	while(i<len)
	{
		if(j==-1 || str[j]!=str[i])
		{
			j++;
			str[j]=str[i];
			i++;
			
		}
		else{
			while(i<len && str[j]==str[i])
			{
				i++;
			}
			j--;
		}
	}
	str[j+1]='\0';
	printf("the answer is -%s",str);
	return 0;
}
