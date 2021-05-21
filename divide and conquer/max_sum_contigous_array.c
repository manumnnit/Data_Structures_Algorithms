//maximum contigious sum in an array

#include<stdio.h>
int m;

int max(int i,int j)
{
	return i>j?i:j;
}


int maxsum(int *a,int n,int table[m])
{
	//time 2n that is o(n) and space is o(n) dynamic programming
	int i,maxsum=0;
	table[0]=max(a[0],0);
	
	for(i=1;i<n;i++)
	table[i]=max(table[i-1]+a[i],0);
	for(i=0;i<n;i++)
	if(maxsum<table[i])
	maxsum=table[i];
	return maxsum;
}

int maxsum1(int *a,int n,int table[m])
{
	//time n that is o(n) and space is o(n) dynamic programming in single scan
	int i,maxsum=0;
	table[0]=max(a[0],0);
	
	for(i=1;i<n;i++)
	{
	
	table[i]=max(table[i-1]+a[i],0);
	if(maxsum<table[i])
	maxsum=table[i];
    }
	
	return maxsum;
}

int maxsum2(int *a,int n,int table[m])
{
	//contigious sum not two contigious numbers
	//time n that is o(n) and space is o(n) dynamic programming in single scan
	int i;
	table[0]=a[0];
	table[1]=max(a[0],a[1]);
	for(i=2;i<n;i++)
	{
		table[i]=max(a[i]+table[i-2],table[i-1]);
	}
	
	
	return table[n-1];
}
int maxsum3(int *a,int n,int table[m])
{
	//contigious sum not three contigious numbers
	//time n that is o(n) and space is o(n) dynamic programming in single scan
	int i;
	table[0]=a[0];
	table[1]=max(a[0],a[1]);
	for(i=2;i<n;i++)
	{
		table[i]=max(a[i]+table[i-2],table[i-1]);
	}
	
	
	return table[n-1];
}
int main()
{
	int size,a[]={-2,11,-4,13,-5,2},i;
	size=sizeof(a)/sizeof(a[0]);
	m=size;
	int table[m];
	
	
	printf("%d\n",maxsum2(a,size,table));
	
}
