//find two repeating elements in the array, range is 1 to n
//problem 19  

//not solved

#include<stdio.h>

int main()
{
    int n,a[100],i,x,y,size,S=0,P=1;
    
    printf("enter the number of elements");   
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	printf("enter element \n");
        scanf("%d",&a[i]);
        }
   
  size=n-2;
  for(i=0;i<n;i++)
  {
  	S=S+a[i];
  	P=P*a[i];
  }
  
   
    return 0;
}

