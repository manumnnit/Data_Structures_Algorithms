//finding k nearest neighbours of median of a given sorted array
//linear time complexity
#include<stdio.h>
#include<math.h>
 
 int median(int *a,int n)
 {
 	
if(n%2==0)
return n/2+1;
else
return n/2;	 
}
	  
	  
	  int main()
 {
 	int a[10]={1,12,15,26,27},x,i,j,n=5,k,count;
 	x=median(a,5);
 	printf(" enter the value of k(must be less than %d\n)",n-1);
 	scanf("%d",&k);
 	i=x-1;
 	j=x+1;
 	count=0;
 	while(i>=0 && j<=n-1 && count<=k)
 	{
 		if(abs(a[i]-a[x])<abs(a[j]-a[x]))
 		{
 			printf("%d\n",a[i]);
 			i--;
		 }
		 else if(abs(a[i]-a[x])>=abs(a[j]-a[x]))
		 {
		 		printf("%d\n",a[j]);
 			j++;
		 	
		 }
		 count++;
	 }
 	
 	return 0;
 }

