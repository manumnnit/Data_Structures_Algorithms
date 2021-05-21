#include<stdio.h>

void charSwap(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
	char a='0',b='1';
	printf("%c-%c\n",a,b);
	charSwap(&a,&b);
	printf("%c-%c\n",a,b);
	return 0;
}
