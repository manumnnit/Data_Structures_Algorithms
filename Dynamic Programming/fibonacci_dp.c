/*
Mandheer Singh
Date:9/5/2021

Problem: Find the fibnocci of given number.
Input: 5
Output: 5

This programm demonstrate the time comparision between recursive solution and Dynamic programming solution.
Function fib(n) : using DP
function fib_recursive(n) : using recursion
*/


#include<stdio.h>

int table[1024];
int count=0; //for counting dynamic programming function calls
int fib(int n)
{
    if(n==0 || n==1)
        return n;

    else{
        if(table[n]!=0)
            return table[n];
        if(table[n-1]==0){
            table[n-1]=fib(n-1);
        }
        if(table[n-2]==0){
            table[n-2]=fib(n-2);
        }
        count++;
        return table[n-1]+table[n-2];
    }

}

int count1=0; //for counting recursive calls
int fib_recursive(int n)
{
    if(n==0 || n==1)
    return n;
    else
        {
            count1++; //to check the no of function calls
            return fib_recursive(n-1)+fib_recursive(n-2);
        }
}

int main()
{
    int a;
    printf("enter the number");
    scanf("%d",&a);
    printf("Value of fibnocci of %d using recursion is %d \n",a,fib_recursive(a));
    printf("Value of fibnocci of %d using dynamic programming is %d \n",a,fib(a));
    printf("function calls in recursion = %d and fumction calls in dynamic programming = %d\n",count1,count);
    
    return 0;
}