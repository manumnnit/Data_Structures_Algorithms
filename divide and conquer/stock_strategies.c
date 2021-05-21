//stock strategeis


#include<stdio.h>

struct interval
{
	int buy;
	int sell;
};


void stock_strategy(int *price,int n)
{
	int i,count=0;
	struct interval sol[n/2 +1];
	while(i<n)
	{
		while(i<n-1  && price[i+1]<=price[i])
		i++;
		
		if(i==n-1)
		{
			printf("no profit from buying\n");
			return;
		}
		sol[count].buy=i++;
		
		while(i<n  && price[i-1]<=price[i])
		i++;
		sol[count].sell=i-1;
		
		printf("buy on the day %d and sell on the day %d\n",sol[count].buy,sol[count].sell);
		count++;
		
		
	}
}

int main()
{
	int size,price[]={100,180,260,310,40,535,695};
	size=sizeof(price)/sizeof(price[0]);
	stock_strategy(price,size);
}
