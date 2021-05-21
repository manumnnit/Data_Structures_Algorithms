
//removing duplicates from string bruteforce
//removing adjacent duplicates

#include <stdio.h>
#include<string.h>



int main()
{
    char str[100000];
    int i,j;
    scanf("%s",str);
    j=0;
    for(i=1;i<=strlen(str);i++)
    {
      while(j>=0 && str[i]==str[j])
	  {
	  	i++;j--;
		}  
		str[++j]=str[i];
       
    }
    
    
    printf("%s",str);
    return 0;
}
