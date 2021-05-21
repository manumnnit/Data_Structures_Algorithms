//wordbreak.c
//Consider the following dictionary 
/*{ i, like, sam, sung, samsung, mobile, ice, 
  cream, icecream, man, go, mango}

Input:  ilike
Output: Yes 
The string can be segmented as "i like".

Input:  ilikesamsung
Output: Yes
The string can be segmented as "i like samsung" or "i like sam sung".
*/
//do it later

#include<stdio.h>
#include<string.h>
#include<malloc.h>
int containword(char *word)
{
	char dictionary[][32]={"mobile","samsung","sam","sung","man","mango",
                           "icecream","and","go","i","like","ice","cream"};
    int size,i;
	size=sizeof(dictionary)/sizeof(dictionary[0]);
	for(i=0;i<size;i++)
	{
		if(!strcmp(word,dictionary[i]))
		  return 1;
	}  
	return 0;                     
}
char* substr(char *str,int p,int len)
{
	char *temp=malloc((sizeof(char)*len)+1);
	int i,j;
	i=p;
	for(j=0;j<len;j++,i++)
	temp[j]=str[i];
	temp[j]='\0';
	//printf("%s\n",temp);
	return temp;
}
int wordbreak(char *word)
{
	
	int len=strlen(word),i;
	if(len==0)
	return 1;
	
	
	for(i=1;i<len;i++)
	{
		
		if(containword(substr(word,0,i)) && wordbreak(substr(word,i,len-i)))
		return 1;
		
	}
	
	return 0;
	
}

int main()
{
	char *p="ilikesamsung";
	wordbreak(p)?printf("yes\n"):printf("no\n");
}
