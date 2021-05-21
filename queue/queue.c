#include<stdio.h>
#include<malloc.h>

typedef struct Queue
{
	int front,rear;
	int capacity;
	int *array;
} Queue;

Queue* createQueue(int size)
{
	Queue *Q=(Queue*)malloc(sizeof(Queue));
	if(!Q)
	{
		printf("memeory error!!");
		return NULL;
	}
	
	Q->front=Q->rear=-1;
	Q->capacity=size;
	Q->array=(int*)malloc(sizeof(int)*Q->capacity);
	if(!Q->array)
	{
		printf("memeory error!!");
		return NULL;
	}
	return Q;
}

int isemptyQueue(Queue *Q)
{
	if(Q)
	{
		if(Q->front==-1)
		return 1;
	}
	return 0;
}

int isfullQueue(Queue *Q)
{
	if(Q)
	{
		if(Q->front==Q->rear+1%Q->capacity)
		return 1;
	}
	return 0;
}

int sizeofQueue(Queue *Q)
{
	    if(Q)
	    return (Q->capacity-Q->front+Q->rear+1)%Q->capacity;
	    return 0;
	    
}

void enqueue(Queue *Q,int item)
{
	if(isfullQueue(Q))
	{printf("queue is full");
	return;
	}
	
	
	if(Q->rear==-1)
	Q->front=Q->rear=0;
	else
	Q->rear++;
	Q->array[Q->rear]=item;
	
	
}

int dequeue(Queue *Q)
{
	int x;
	if(isemptyQueue(Q))
	{
		printf("queue is empty");
	return -99;
	}
	x=Q->array[Q->front];
	if(Q->front==Q->rear)
	Q->front=Q->rear=-1;
	else
	Q->front++;
	return x;
	
}

void deleteQueue(Queue *Q)
{
	if(Q){
		if(Q->array);
		free(Q->array);
	}
	free(Q);
}

int main()
{
	Queue *Q=createQueue(6);
	enqueue(Q,5);
	enqueue(Q,4);
	enqueue(Q,3);
	enqueue(Q,1);
	printf("%d",dequeue(Q));
		printf("%d",dequeue(Q));
			printf("%d",dequeue(Q));	printf("%d",dequeue(Q));
				printf("%d",dequeue(Q));
	return 0;
}
