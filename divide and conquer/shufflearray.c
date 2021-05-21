//stock strategies

#include<stdio.h>




void shuffle_array(int *a,int l,int r)
{
	int i,c,q,k,temp;
	if(l==r)
	return;
	c=l+(r-l)/2;
	q=1+l+(c-l)/2;
	
	for(k=1,i=q;i<=c;i++,k++)
	{
		temp=a[i];
		a[i]=a[c+k];
		a[c+k]=temp;
	}
	shuffle_array(a,l,c);
	shuffle_array(a,c+1,r);
	
}

int main()
{
	int size,a[]={1,2,3,4,5,6,7,8},i;
	size=sizeof(a)/sizeof(a[0]);
	shuffle_array(a,0,size-1);
	for(i=0;i<size;i++)
	printf("%d\t",a[i]);
	
}
