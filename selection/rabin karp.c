// rabin karp pattern matching
// for number at starting
// complexity o(mn)

#include<stdio.h>
#include<string.h>

int hash(char *str,int m,int i)
{
	int j,p=0;
	if(str == NULL){
	printf("error str is null\n");
	
	}
	
	for(j=i;j<i+ m;j++)
	p=10*p+(str[j]-'0');
	
//	printf("%d\n",p);
	
	return p;
	
}


int main()
{
	char t[100],p[100]; int m,n,i,pval,tval;
	printf("enter the text");
	scanf("%s",t);
	printf("enter the pattern");
	scanf("%s",p);
	m=strlen(p);
	n=strlen(t);
	pval=hash(p,m,0);
	printf("%d\n",pval);
	tval=hash(t,m,i);
	for(i=0;i<n-m+1;i++)
	{
		if(tval==pval)
		{
		printf("pattern found at index %d",i+1);
		break;
	    }
	    printf("%d\n",tval);
	    tval=10*(tval%(10^m-1))+(t[i+m]-'0');
	}
	if(i==m+n-1)
	printf("pattern doesnot exists");
}
