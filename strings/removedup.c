
//removing duplicates from string bruteforce

#include <stdio.h>

int check(char *str,char c,int i)
{
    int j;
    for(j=0;j<i;j++)
    {
        if(str[j]==c)
        return 1;
    }
    return 0;
}

int main()
{
    char str[100000];
    int i,j,k;
    scanf("%s",str);
    j=1;
    for(i=1;i<strlen(str);i++)
    {
        
        if(!check(str,str[i],i))
        {
        str[j]=str[i];
        j++;
        }
        
    }
    str[j]='\0';
    printf("%s",str);
    return 0;
}
