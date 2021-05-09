/* Mandheer Singh
Date-3/5/2021
Problem- Find Longest Common Subsequence 
Given Two Strings of length m and n
Find length of the longest common subsequence

Example:-
X = 'ABCBDAB'
Y= 'BDCABA'

Output= 4
*/

#include<stdio.h>

int count=0;
int table[1024][1024];

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
    else if(x[i]==y[j]){
        count++;
        return 1 + lcsrecursive(x,i+1,m,y,j+1,n); 
        }
    else { count++;
        return max(lcsrecursive(x,i+1,m,y,j,n),lcsrecursive(x,i,m,y,j+1,n));
    }
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

int count1=0;
// recursive solution
int lcs_dp(char x[],int i,int m,char y[],int j,int n)
{ 
    if ((i==m) || (j==n))
        return 0;
    else if(x[i]==y[j]){
            
            if (table[i+1][j+1]>=0){
                
            table[i][j]=1+table[i+1][j+1];
            return table[i][j]; 
            }
            else { 
                table[i+1][j+1]=lcs_dp(x,i+1,m,y,j+1,n);
                table[i][j]=1+table[i+1][j+1];
                count1++;
                return table[i][j];}
               // return max(lcsrecursive(x,i+1,m,y,j,n),lcsrecursive(x,i,m,y,j+1,n));
                    }

    else{ 
            if(table[i][j+1]<0){
                table[i][j+1]=lcs_dp(x,i,m,y,j+1,n); }
            if(table[i+1][j]<0){ 
                table[i+1][j]=lcs_dp(x,i+1,m,y,j,n);}
            count1++;
            return table[i][j]=max(table[i][j+1],table[i+1][j]);


    }
}


int main()
{   int i,j;
    //char x[]="ABCBDAB",y[]="BDCABA";
   //char x[]="abc",y[]="bc";
   char x[]="ABCBDAB",y[]="IJK";
    int m,n;
    m=len(x);
    n=len(y);
    //intializing our table with large negative value
    for(i=0;i<1024;i++)
        for(j=0;j<1024;j++)
            table[i][j]=-99;
    printf("%d\n",lcsrecursive(x,0,m,y,0,n));
    printf("%d\n",lcs_dp(x,0,m,y,0,n));
    printf("In recursion no of function calls %d and string lengths were %d and %d\n",count,m,n);
    printf("In DP no of function calls %d and string lengths were %d and %d\n",count1,m,n);
    return 0;
}