/*Maga and Alex are good at string manipulation problems. Just now they have faced a problem related to string. But it is not a standard string problem. They have no idea to solve it. They need your help.

A string is called unique if all characters of string are distinct.

String s1
is called subsequence of string s2 if s1 can be produced from s2 by removing some characters of s2

.

String s1
is stronger than s2 if s1 is lexicographically greater than s2

.

You are given a string. Your task is to find the strongest unique string which is subsequence of given string.

Input:

first line contains length of string.
second line contains the string.

Output:

Output the strongest unique string which is subsequence of given string.

Constraints:

1=|S|=100000

All letters are lowercase English letters.*/

#include <stdio.h>

void swap(char *x,char *y)
{
    char temp;
    temp=*x;
    *x=*y;
    *y=temp;
}





int main()
{
    char str[100001];
    int index[100001];
    long long int i,max,j,n,temp;
    scanf("%lld",&n);
    for(i=0;i<=n;i++)
    {
    scanf("%c",&str[i]);
    index[i]=i;
    
    }
    
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(str[j+1]<str[j])
            {
            swap(&str[j],&str[j+1]);
            temp=index[j];
            index[j]=index[j+1];
            index[j+1]=temp;
            
            }
        }
    }
    
    //printf("%s\n",str);
   i=n;
   printf("%c",str[i]);
   i--;
   while(i>=1)
   {
       if(index[i+1]<index[i])
       printf("%c",str[i]);
       i--;
       
   }
    //printf("Hello World!\n");
    return 0;
}
