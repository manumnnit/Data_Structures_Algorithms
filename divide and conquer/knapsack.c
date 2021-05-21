// 0/1 knapsackproblem
#include<stdio.h>

int m,l;

int max(int i,int j)
{
	return i>j?i:j;
}

int knapsack(int *wt,int *val,int W,int n)
{
	printf("knap(%d,%d)\n",W,n);
	if(W==0 || n==0)
	return 0;
	
	if(wt[n-1]>W)
	return knapsack(wt,val,W,n-1);
	
	else
	return max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
}

int fknapsack(int *wt,int *val,int W,int n,int table[m][l])
{
	printf("fknap(%d,%d)\n",W,n);
	if(W==0 || n==0)
	return 0;
	
	if(wt[n-1]>W)
	{
		if(table[W][n-1]==-99)
		table[W][n-1]=fknapsack(wt,val,W,n-1,table);
		
		return table[W][n-1] ;
	}
	
	
	else
	{
		
		if(table[W][n-1]==-99)
		table[W][n-1]=fknapsack(wt,val,W,n-1,table);
		if(table[W-wt[n-1]][n-1]==-99)
		table[W-wt[n-1]][n-1]=fknapsack(wt,val,W-wt[n-1],n-1,table);
	
	 table[W][n]=max(val[n-1]+table[W-wt[n-1]][n-1],table[W][n-1]);
	return table[W][n];
   }
}

int main()
{
	int size,val[]={10,40,50,70,100},wt[]={1,3,4,5,6},W=9,i,j;
	size=sizeof(val)/sizeof(val[0]);
	m=W+1; l=size+1;
	int table[m][l];
	for(i=0;i<m;i++)
	for(j=0;j<l;j++)
	table[i][j]=-99;
	
	printf("%d\n",fknapsack(wt,val,W,size,table));
	return 0;
}
