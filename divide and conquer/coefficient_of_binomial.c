#include<stdio.h>

int m,n;

int coeff(int n,int k)
{
	
	printf("%d-%d\n",n,k);
	
	
	if (n==k || k==0)
	return 1;
	
	return coeff(n-1,k-1)+coeff(n-1,k);
	
}

//using dp
int fcoeff(int i,int k,int table[m][n])
{
	
	
printf("%d-%d\n",i,k);
	
	if (i==k || k==0)
	return 1;
	
	
		
		if(table[i-1][k-1]==-99)
		table[i-1][k-1]=fcoeff(i-1,k-1,table);
		if(table[i-1][k]==-99)
		table[i-1][k]=fcoeff(i-1,k,table);
		table[i][k]=table[i-1][k-1]+table[i-1][k];
		return table[i][k];

	
	
	
}


int main()
{
	int i=5,j=3;
	m=i+1; n=j+1;
	int table[m][n];
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	table[i][j]=-99;
	printf("%d-->%d\n",m-1,n-1);
	printf("%d",fcoeff(m-1,n-1,table));
	return 0;
}
