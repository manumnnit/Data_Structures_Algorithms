#include<stdio.h>

int ugly(int n)
{
	while(n%2==0)
	n=n/2;
	while(n%3==0)
	n=n/3;
	while(n%5==0)
	n=n/5;
	
	if(n==1)
	return 1;
	else return 0;
}

int print_n_ugly(int n){
	//slow in speed
	int i=1,count=0;
	while(count<n)
	{
	printf("%d-%d\n",count,i);
		if(ugly(i))
		count++;
		i++;
	}
	
	return i-1;
	
}

int fprint_n_ugly(int n)
{
	//using dynamic programming time o(n) space o(n)
	int table[n+1],i=1,j=1,k=1,l;
	
	for(l=0;l<=n;l++)
	table[l]=0;
	i=j=k=table[1]=1;
	for(l=2;l<=n;l++)
	{
		table[l]=2*table[i]<3*table[j]?(2*table[i]<5*table[k])?2*table[i]:5*table[k]:3*table[j]<5*table[k]?3*table[j]:5*table[k];
		if(table[l]==2*table[i])
		i++;
		else if(table[l]==3*table[j])
		j++;
		else
		k++;
		if(table[l]==table[l-1])
		l=l-1;
		//printf("%d\n",table[l]);
		/*if((2*i)<(3*j))
		{
			if((2*i)<(5*k))
			{
				table[l]=2*i;
				i++;
			}
			else
			{
				table[l]=5*k;
			     k++;
			}
		}
		else if((3*j)<(5*k))
		{
			table[l]=3*j;
			j++;
		}
		else
		{
			table[l]=5*k;
			k++;
		}*/
		
	}
	
//	for(l=1;l<=n;l++)
//	printf("%d-\t",table[l]);
	return table[n];
}

int main()
{
	int a=150;
	printf("%d",fprint_n_ugly(a));
	return 0;
}
