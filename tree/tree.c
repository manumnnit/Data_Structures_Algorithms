#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

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


typedef struct tree
{ 
int data;
struct tree *left,*right;
} tree;


tree* insert_left(tree *root,int data)
{
	tree *temp,*newnode;
	printf("in left\n");
	newnode=(tree*)malloc(sizeof(tree));
	if(!newnode){
		printf("node could not be created!!");
		return;
	}
   newnode->data=data;
	newnode->left=newnode->right=NULL;
	if(!root)
	{
		return newnode;
	}
	temp=root;
	 while(root->left)
	 root=root->left;
	root->left=newnode;
	return temp;
}

tree* insert_right(tree *root,int data)
{
	tree *temp,*newnode;
	printf("in right\n");
	newnode=(tree*)malloc(sizeof(tree));
	if(!newnode){
		printf("node could not be created!!");
		return;
	}
   newnode->data=data;
	newnode->left=newnode->right=NULL;
	if(!root)
	{
		return newnode;
	}
	temp=root;
	 while(root->right)
	 root=root->right;
	root->right=newnode;
	return temp;
}

void preorder(tree *root)
{
	if(root)
	{
		printf("%d-",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

int main()
{
	int i,j,n;
	tree *root,*temp;
	printf("welcome you are about to create your own tree\n");
	printf("enter the root element-");
	scanf("%d",&n);
	root=(tree*)malloc(sizeof(tree));
	if(!root)
	{
		printf("could not be created!!");
		return -1;
	}
	root->data=n;
	root->left=root->right=NULL;
	while(1)
	{
		printf("enter your choice 1.insert a node in left subtree \t2.insert a node in right subtree \n 3.traverse tree 4.exit");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				 printf("enter the element to insert:");
				 scanf("%d",&n);
				 root=insert_left(root,n);
				 break;
			case 2:	printf("enter the element to insert:");
				 scanf("%d",&n);
				 root=insert_right(root,n);
				 break; 
			case 3:
			      preorder(root);
			       break;
			       
	        case 4: exit(0);
	        
			deafault:printf("wrong choice!!");
			  break;	
		}
		
	}
	
	return 0;
	
}
