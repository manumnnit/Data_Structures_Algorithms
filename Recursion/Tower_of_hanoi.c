#include<stdio.h>

void toh(char l,char m,char r, int n)
{
    if(n<=0)
     return;
    else{
        toh(l,r,m,n-1);
        printf("Move %c-->%c\n",l,r);
        toh(m,l,r,n-1);
        }
}

int main()
{
int n=4;
toh('l','m','r',n);
return 0;
}




