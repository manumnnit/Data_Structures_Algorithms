// rabin karp pattern matching
// for number at starting

#include<stdio.h>
#include<string.h>

int hash(char *str,int m)
{
	int i,p=0;
	
	for(i=0;i<m;i++)
	p=10*p+str[i];
	
	return p;
	
}

int main()
{
	char t[100],p[100],m,n,i,pval;
	printf("enter the text");
	scanf("%s",t);
	printf("enter the pattern");
	scanf("%s",p);
	m=strlen(p);
	t=strlen(t);
	pval=hash(p,m);
	for(i=0;i<m+n-1;i++)
	{
		if(hash(t,i+m)==pval)
		{
		
		printf("%d",i);
		break;
	    }
		
	}
	if(i==m+n-1)
	printf("pattern doesnot exists");
}
