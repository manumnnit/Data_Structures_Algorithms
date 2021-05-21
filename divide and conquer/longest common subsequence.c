

//finding longest common subsequence
#include<stdio.h>
#include<string.h>

int max(int i,int j)
{
	return (i>j?i:j);
}

int lcs(char *x,char *y,int i,int j)
{
 
 printf("%d-%d\n",i,j);
   if(i<0 || j<0)
   return 0;
   
else
{
		if(x[i]==y[j])
	return 1+lcs(x,y,i-1,j-1);
	
	else 
	return  max(lcs(x,y,i,j-1),lcs(x,y,i-1,j));
	
}
}


int main()
{
	char x[]="abbabb";
	char y[]="baabab";
	int answer;
	answer=lcs(x,y,strlen(x)-1,strlen(y)-1);
	printf("%d",answer);
}


