#include<stdio.h>
#include<string.h>

int main(){
	
	int j= 0;
	int p=0;
	
	char str[] = "249";
	
	if(str == NULL){
	printf("error str is null\n");
    }
	
	for(j=0;j<strlen(str);j++)
	  {
	  p=10*p+(str[j] - '0');
	}
	
	printf("%d\n",p);
	

	return 0;
	
}
