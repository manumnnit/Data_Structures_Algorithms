/*
Mandheer Singh
Date:10/5/2021

Problem: Find maximum sum of contigious block in a given array
Input: 1 -3 4 -2 -1 6
Output: 7

*/

#include<stdio.h>

int count=0;
int max(int a,int b,int c){
    printf("from max %d -- %d\n",a,b);
    return a>b?(a>c?a:c):(b>c?b:c);
}
int sum(int *a,int i,int j)
{ int m=0;
    if(i==j)
        return a[i];

    else{ count++;
            return a[i]+sum(a,i+1,j);
    }
}

int max_sum_r(int *a,int i,int j)
{int m=0;
    if(i==j)
        return a[i];

    else{ m=sum(a,i+1,j);
    return max(a[i],a[i]+m,m);
        
    }
}

int main()
{
    int a[]={1,-3,4,-2,-1,6};
    
    printf("Value maximum sum is %d using recursion \n",max_sum_r(a,0,5));
    
    printf("function calls in recursion = %d\n",count);
    
    return 0;
}