#include<stdio.h>
#include<string.h>

//wrong programm


void combinations(char *combination,char *original,int depth,int start)
{
	int i,length=strlen(original);
	
	//printf("%d",depth);
	
	for(i=start;i<length;i++)
	{
	
	combination[depth]=original[i];
	combination[depth+1]="\0";
	printf("%s\n",combination);
	if(i<length-1)
	combinations(combination,original,depth+1,start+1);
    }
	
}

int main()
{
	char str[100]="abcd",com[100];
	combinations(com,str,0,0);
}
