/* Mandheer Singh
Date-3/5/2021
Problem- Find Longest Common Subsequence 
Given Two Strings of length m and n
Find length of the longest common subsequence

Example:-
X = 'ABCBDAB'
Y= 'BDCABA'*/

#include<stdio.h>

int max(int a,int b)
{
    if (a>b)
        return a;
    else
        return b;
}

// recursive solution
int lcsrecursive(char x[],int i,int m,char y[],int j,int n)
{
    if ((i==m) || (j==n))
        return 0;
    else if(x[i]==y[j])
        return 1 + lcsrecursive(x,i+1,m,y,j+1,n);
    else 
        return max(lcsrecursive(x,i+1,m,y,j,n),lcsrecursive(x,i,m,y,j+1,n));
}

//length of string
int len(char x[])
{
    int i=0;
    while(x[i]!='\0')
    {
        i=i+1;
    }
    return i;
}

int main()
{
    char x[]="ABCBDAB",y[]="BDCABA";
    int m,n;
    m=len(x);
    n=len(y);
    printf("%d",lcsrecursive(x,0,m,y,0,n));
    return 0;
}