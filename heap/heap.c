//creating heap and heapsort
#define maxheap 0
#define minheap 1

#include<malloc.h>
#include<stdio.h>

typedef struct heap
{
	int *array;
	int capacity;
	int count;
	int heaptype;
} heap;

void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

heap* createheap(int capacity,int type)
{
   heap *H=(heap*)malloc(sizeof(heap));
    if(!H)
        { printf("memory error");
          return NULL;
        }
   
   H->array=(int *)malloc(sizeof(int)*capacity);
   if(!H->array)
   { printf("memory error");
          return NULL;
        }
    
    H->capacity=capacity;
    H->count=0;
    H->heaptype=type;
    return H;

}


int parent(heap *H,int i)
{
	if(i<=0 && H->count<i)
	return -1;
	else
	return (i-1)/2;
}

int leftchild(heap *H,int i)
{
	int l=2*i+1;
	if(l>=H->count)
	return -1;
	else
	return l;
}

int rightchild(heap *H,int i)
{
	int r=2*i+2;
	if(r>=H->count)
	return -1;
	else
	return r;
}

int getmax(heap *H)
{ 
if(H->count==0)
return -1;
return H->array[0];
}

void percolatedown(heap *H,int i)
{
	int l,r,max,temp;
	//printf("*%d*\n",i);
	l=leftchild(H,i);
	r=rightchild(H,i);
	max=i;
	if(l!=-1 && H->array[l]>H->array[max])
	max=l;
	if(r!=-1  && H->array[r]>H->array[max])
	max=r;
	if(max!=i)
	{
		swap(&H->array[i],&H->array[max]);
		percolatedown(H,max);
	}
	else
	return;
	
}

int deletemax(heap *H)
{
	int temp;
	if(!H || H->count==0)
	return -1;
	temp=H->array[0];
	swap(&H->array[0],&H->array[H->count-1]);
	H->count--;
	percolatedown(H,0);
	return temp;
	
}




void resizeheap(heap *H)
{
	int *arrayold=H->array,i;
	H->array=(int*)malloc(sizeof(int)*H->capacity*2);
	if(!H->array)
	{
	printf("memory error");
	return;
	}
	for(i=0;i<H->count;i++)
	H->array[i]=arrayold[i];
	H->capacity=H->capacity*2;
	free(arrayold);
}


void insert(heap *H,int data)
{
	int i,p;
	if(H->count==H->capacity)
	{
		printf("heap is full please wait\n");
		printf("resizing heap......\n");
		resizeheap(H);
	}
	
	i=H->count;
	

	while(i>0 && data>H->array[(i-1)/2])
	{
		H->array[i]=H->array[(i-1)/2];
		i=(i-1)/2;
		//	printf("%d**%d\n",i,(i-1)/2);
		
	}
	
	H->array[i]=data;
	H->count++;
}

void destroyHeap(heap *H)
{
	if(!H)
	return;
	if(H->array)
	free(H->array);
	free(H);
	H=NULL;
}

heap* buildheap(int *a,int n)
{
	int i;
	heap *H=createheap(n,0);
	if(!H)
	{printf("memory error\n");
	return NULL;
	}
	printf("created HEAP....\n");
	for(i=0;i<n;i++)
	H->array[i]=a[i];
	H->count=n;
	//i=(n-1)/2;
	for(i=(n-1)/2;i>=0;i--)
	percolatedown(H,i);
	return H;
	
}

void heapsort(int *a,heap *H,int n)
{
	int i;
	
	for(i=n-1;i>=0;i--)
	{
		a[i]=deletemax(H);
	}

	
	
}

int main()
{
    int n,a[100],i,j;
    heap *H;
    printf("enter the number of elements");   
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	printf("enter element");
        scanf("%d",&a[i]);
        
    }
    H=buildheap(a,n);
   
    //printf("%d\n",deletemax(H));
    
   
    
   
    heapsort(a,H,n);
    
    
    
      printf("after sorting\n");
    for(i=0;i<n;i++)
    printf("%d\n",a[i]);
    
    destroyHeap(H);
    //printf("Hello World!\n");*/
    return 0;
}

