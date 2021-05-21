#include<stdio.h>
 int main()
 {
 	int a[20],s[20],i,j,n;
 	printf("enter the no of days-");
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
 	{
 		printf("enter the price on day %d-",i+1);
 		scanf("%d",&a[i]);
 		
	 }
	 
	 for(i=0;i<n;i++)
	 {
	 	j=1;
	 	while(j<=i && a[i]>a[i-j])
	 	j++;
	 	s[i]=j;
	 }
	 
	 printf("the stock span is as follows:");
	 
	 for(i=0;i<n;i++)
 	{
 		printf(" price on day %d is %d and span is %d\n",i+1,a[i],s[i]);
 		
 		
	 }
	 
	 
 	
 }
