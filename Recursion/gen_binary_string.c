#include<stdio.h>
//Mandheer Singh
// generating all binary string using recuirsion
// n length string k-ary string
void binary(char *a, int n,int k)
{
    int i;
    if(n<=0){
printf("%s\n",a);
     return;}
    else{
        for (i=0;i<k;i++){
            a[n-1]=i+48;
            binary(a,n-1,k);
        }
        
        
        }
}

int main()
{
int n=3,k=3;
char a[]={'0','0','0'};
//printf("%s",a);
binary(a,n,k);

return 0;
}




