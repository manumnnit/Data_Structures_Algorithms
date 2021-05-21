//given two sorted arrays find the median of 2n elemnts in logn time

#include<stdio.h>
 
 int median(int *a,int n)
 {
 	
if(n%2==0)
return (a[n/2]+a[n/2+1])/2;
else
return a[n/2];	 
	  }
	  
int max(int *x,int *y)
	  {
	  	return *x>*y?*x:*y;
	  }
	  
int min(int *x,int *y)
	  {
	  	return *x<*y?*x:*y;
	  }
 int getmedian(int *a,int *b,int n)
 {
 	int m1,m2;
 	if(n<0)
 	return -1;
 	if(n==1)
 	return (a[0]+b[0])/2;
 	
 	if(n==2)
 	return (max(&a[0],&b[0])+min(&a[1],&b[1]))/2;
 	m1=median(a,n);
 	m2=median(b,n);
 	
 	if(m1==m2)
 	return m1;
 	
 	else if(m1<m2)
 	{
	 if(n%2==0)
 	return getmedian(a+n/2-1,b,n-n/2+1);
 	else
 	return getmedian(a+n/2,b,n-n/2);
    }
    
    else 
    {
    	if(n%2==0)
 	return getmedian(b+n/2-1,a,n-n/2+1);
 	else
 	return getmedian(b+n/2,a,n-n/2);
	}
 }
 
 int main()
 {
 	int a[100]={1,12,15,26,38},b[100]={2,13,17,30,45};
 	printf("%d",getmedian(a,b,5));
 	return 0;
 }

