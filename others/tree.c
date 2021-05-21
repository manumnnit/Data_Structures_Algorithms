#include<stdio.h>
 #include<malloc.h>
 
  struct node
 {
 int data;
 struct node *left;
 struct node *right;
 };
 
 typedef struct queue
 {
 	int front,rear;
 	int capacity;
 	struct node **array;
 	
 } queue;
 
 queue* createqueue(int size)
 {
 	queue *Q=(queue*)malloc(sizeof(queue));
 	if(!Q)
 	{
 		printf("memeory error");
 		return NULL;
	 }
	 Q->front=Q->rear=-1;
	 Q->capacity=size;
	 Q->array=(struct node**)malloc(sizeof(struct node*)*Q->capacity);
	 if(!Q->array)
	 {
 		printf("memeory error");
 		return NULL;
	 }
	 return Q;
 }
 
 int isfull(queue *Q)
 {
 	if(Q)
 	{
	 
 	if(Q->front==(Q->rear+1)%Q->capacity)
 	return 1;
 	else 
	 return 0;
    }
 }

void enqueue(queue *Q,struct node *root)
{
	if(isfull(Q))
	{
		printf("queue is full");
		return;
	}
	
	if(Q->rear==-1)
	Q->front=Q->rear=0;
	else
	Q->rear=(Q->rear+1)%Q->capacity;
	Q->array[Q->rear]=root;
}

int isempty(queue *Q)
{
	if(Q)
	{
		if(Q->front==-1)
		return 1;
		else 
		return 0;
	}
}

struct node* dequeue(queue *Q)
{
	struct node *temp;
	if(isempty(Q))
	{
		printf("queue is empty");
		return NULL;
	}
	temp=Q->array[Q->front];
	if(Q->rear==Q->front)
	Q->rear=Q->front=-1;
	else
	Q->front=Q->front+1%Q->capacity;
	return temp;
	
}

void deletequeue(queue *Q)
{
	if(Q)
	{
		if(Q->array)
		free(Q->array);
		free(Q);
	}
}



 struct node* getnode(int data)
 {
 struct node *p=(struct node*)malloc(sizeof(struct node));
 if(!p)
 {
 printf("memory error");
 return NULL;
 }
 p->data=data; p->left=p->right=NULL;
 return p;
 }

 void traverse(struct node *root)
 {
 if(root==NULL)
 return;
printf("%d-->",root->data);
 traverse(root->left);
 
 traverse(root->right);
 }

 void mirror(struct node *root)
 {
 struct node *temp;
 if(!root)
 return;
 temp=root->left;
 root->left=root->right;
 root->right=temp;
 mirror(root->left);
 mirror(root->right);
 }

 struct node* clone(struct node *root)
 {
 struct node *temp;
 if(!root)
 return NULL;
 temp=getnode(root->data);
 temp->left=clone(root->left);
 temp->right=clone(root->right);
 return temp;

 }
 
 void levelorder(struct node *root)
 {
 	queue *Q=createqueue(20);
 	struct node *temp;
 	if(!root)
 	{
 	return;	
	 }
	 enqueue(Q,root);
	 while(!isempty(Q))
	 {
	 	temp=dequeue(Q);
	 	printf("%d-->",temp->data);
	 	if(temp->left)
	 	enqueue(Q,temp->left);
	 	if(temp->right)
	 	enqueue(Q,temp->right);
	 	
	 }
	
deletequeue(Q);	 
	 
 }
 
  int  hieght(struct node *root)
 {
 	queue *Q=createqueue(20);
 	struct node *temp;
 	int level=0;
 	if(!root)
 	{
 	return 0;	
	 }
	 enqueue(Q,root);
	 level++;
	  enqueue(Q,NULL);
	 while(!isempty(Q))
	 {
	 	temp=dequeue(Q);
	 	if(!temp)
	 	{
	 		if(!isempty(Q))
	 		enqueue(Q,NULL);
	 		level++;
		 }
		 else{
		 
	 	
	 	if(temp->left)
	 	enqueue(Q,temp->left);
	 	if(temp->right)
	 	enqueue(Q,temp->right);
	   }
	 	
	 }
deletequeue(Q);	
return level; 
	 
 }
 
 int max(int i,int j)
 {
 	return i>j?i:j;
 }
 
 int maxintree(struct node *root)
 {
 	if(!root)
 	return -1;
 	else
 	return max(root->data,max(maxintree(root->left),maxintree(root->right)));
 }
 
 int search(struct node *root,int data)
 {
 	if(!root)
 	return 0;
 	if(root->data==data)
 	return 1;
 	return search(root->left,data)||search(root->right,data);
 }


 int size(struct node *root)
 {
 	if(!root)
 	return 0;
 	
 	return 1+size(root->left)+size(root->right);
 }
 
int count_leaf(struct node *root)
{
	if(!root)
	return 0;
	if(!root->left && !root->right)
	return 1;
	return count_leaf(root->left)+count_leaf(root->right);
}

int count_internal(struct node *root)
{//wrong answer
	if(!root)
	return 0;
	if(!root->left && !root->right)
	return 0;
	return 1+count_internal(root->left)+count_internal(root->right);
}
void printpath(int path[],int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		printf("%d-->",path[i]);
	}
	printf("end\n");
}
void printallpath(struct node *root,int path[],int pathlen)
{
	if(!root)
	return;
	path[pathlen]=root->data;
	pathlen++;
	if(!root->left && !root->right)
	printpath(path,pathlen);
	else
	{
		printallpath(root->left,path,pathlen);
		printallpath(root->right,path,pathlen);
	}
}

int ispathwithsumk(struct node *root,int k)
{
	if(!root)
	return 0;
	if(!root->left && !root->right && root->data==k)
	return 1;
	return ispathwithsumk(root->left,k-root->data) || ispathwithsumk(root->right,k-root->data);
}

int sumofall(struct node *root)
{
	if(!root)
	return 0;
	return root->data+sumofall(root->left)+sumofall(root->right);
}

int ismirror(struct node *root1,struct node *root2)
{

	if(!root1 && !root2)
	return 1;
	if(!root1 || !root2)
	return 0;
	if(root1->data != root2->data)
	return 0;
	else
	return ismirror(root1->left,root2->right) && ismirror(root1->right,root2->left);
	
}
int mirrorimageutil(struct node *left,struct node *right,int k)
{
	if(!left && !right)
	return 0;

	if(left && left->data==k)
	return right?right->data:0;
	if(right && right->data==k)
	return left?left->data:0;
	
if	(mirrorimageutil(left->left,right->right,k)) 
return mirrorimageutil(left->left,right->right,k);

else
return mirrorimageutil(left->right,right->left,k)?mirrorimageutil(left->right,right->left,k):0;//work pending
}

int mirrorimage(struct node *root,int k)
{
	int m;
	if(!root)
	return -1;
	if(root->data==k)
	return root->data;
	m=mirrorimageutil(root->left,root->right,k);
	if(m==0)
	return -1;
	else return m;
}
int main()
 {
struct node *root=getnode(1),*root1;
int path[20];
 root->left=getnode(2);
 root->right=getnode(3);
 root->left->left=getnode(4);
 root->left->right=getnode(15);
 root->right->left=getnode(6);
 root->right->right=getnode(7);
 root->right->right->left=getnode(12);
 //root->right->right->right=getnode(8);
 
 //levelorder(root);
 //traverse(root);
 //printf("\n%d\n",count_internal(root));
// printallpath(root,path,0);
//ispathwithsumk(root,14)?printf("yes"):printf("no");
 //printf("%d\n",sumofall(root));
 /*root1=clone(root);
 traverse(root1);
 printf("end\n");
 mirror(root1);
 traverse(root1);
 printf("end\n");
 traverse(root);
 printf("end\n");
 ismirror(root,root1)?printf("yes"):printf("no");*/
 printf("%d\n",mirrorimage(root,6));
 return 0;
 }
