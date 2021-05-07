#include<stdio.h>

int is_sorted(int *a, int n)

{
    // function to check if array is sorted in increasing order or not
    if (n==1)
    return 1;
    return (a[n-2]>a[n-1]?-1:is_sorted(a,n-1));
    
}

void reverse(int *a,int n)
{
    // function to print array in reverse order
    if (n==1){
        printf("%d",a[n-1]);
        return;
    }
    else{
        printf("%d\n",a[n-1]);
        reverse(a,n-1);

    }
}

int main()
{
int n=5,a[5]={12,13,16,18,19};
if(is_sorted(a,n)==-1)
    printf("Not Sorted");
else
printf("sorted");

reverse(a,n);


return 0;
}




