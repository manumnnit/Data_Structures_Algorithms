

//finding longest common subsequence
//using dynamic programming
//o(n2)
#include<stdio.h>
#include<string.h>
 int m,n;

int max(int i,int j)
{
	return (i>j?i:j);
}

int lcs(char *x,char *y,int i,int j,int table[m+1][n+1])
{
 
 printf("%d--->%d\n",i,j);
   if(i<=0 || j<=0)
   return 0;
   
else
{
		if(x[i]==y[j])
		{
			
			if(table[i-1][j-1]==-99)
			table[i-1][j-1]=lcs(x,y,i-1,j-1,table);
			printf("%d\n",table[i-1][j-1]);
		
	    return 1+table[i-1][j-1];
	    
    }
	
	else 
	{
		if(table[i-1][j]==-99)
			table[i-1][j]=lcs(x,y,i-1,j,table);
			
	    if(table[i][j-1]==-99)
			table[i][j-1]=lcs(x,y,i,j-1,table);		

	return  max(table[i][j-1],table[i-1][j]);

    }
	
}
}


int main()
{
	char x[]="abbabb";
	char y[]="baabab";
	int answer,i,j;
	m=strlen(x);
	n=strlen(y);
	int table[m+1][n+1];
	//printf("%d-%d\n",m,n);
	for(i=0;i<=m;i++)
	for(j=0;j<=n;j++)
	table[i][j]=-99;
	
	
	answer=lcs(x,y,m,n,table);
	printf("%d",answer);
}


