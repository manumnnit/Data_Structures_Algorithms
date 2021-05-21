#include<stdio.h>
#include<limits.h>

//matrix chain multiplication
int size;

int mcm(int *p,int i,int j)
{
	printf("%d-%d\n",i,j);
	if(i==j)
	return 0;
	
	int k,count,min=INT_MAX;
	
	for(k=i;k<j;k++)
	{
		count = mcm(p,i,k)+mcm(p,k+1,j)+p[i-1]*p[k]*p[j];
		if(count<min)
		min= count;
	}
	
	return min;
}
//using dynamic programming
//o(n3)
int fastmcm(int *p,int i,int j,int table[size][size])
{
	printf("%d-%d\n",i,j);
	if(i==j)
	return 0;
	int k,min=INT_MAX;
	
	for(k=i;k<j;k++)
	{
		if(table[i][k]==-99)
		table[i][k]=fastmcm(p,i,k,table);
		if(table[k+1][j]==-99)
		table[k+1][j]=fastmcm(p,k+1,j,table);
		table[i][j]=table[i][k]+table[k+1][j]+p[i-1]*p[k]*p[j];
		
		if(table[i][j]<min)
		min= table[i][j];
	}
	
	return min;
	
}

int main()
{
	int p[]={40,20,30,10,30},i,j;
	size=sizeof(p)/sizeof(p[0]);
	int table[size][size];
	for(i=0;i<size;i++)
	for(j=0;j<size;j++)
	table[i][j]=-99;
	printf("%d",fastmcm(p,1,size-1,table));
	return 0;
}
