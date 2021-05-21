#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	int data;
	struct node *left,*right;
} node;

node* getnode(int data)
{
	node *temp;
	temp=(node*)malloc(sizeof(struct node));
	if(!temp)
	{
		printf("memory error");
		return NULL;
	}
	temp->data=data;
	temp->left=temp->right=NULL;
}

node* max(node* root)
{
	if(!root)
	return NULL;
	if(!root->right)
	return root;
	else
	return max(root->right);
}
node* min(node* root)
{
	if(!root)
	return NULL;
	if(!root->left)
	return root;
	else
	return min(root->left);
}

node* insert(node* root,int data)
{
	struct node *temp;
	if(!root)
	{
		temp=getnode(data);
		if(!temp)
	{
		printf("memory error");
		return NULL;
	}
		  else 
		  return temp;
     }
     
     if(root->data==data)
     {
     	printf("duplicate item!!");
     	return root;
	 }
	 
	 
	 else if(root->data<data)
	 root->right=insert(root->right,data);
	 
	 else
	 root->left=insert(root->left,data);
}



node* delete(node* root,int data)
{
	struct node *temp;
	if(!root)
	{
	  printf("element is not there!!");
		return NULL;
     }
     
    
	 
	  if(root->data<data)
	 root->right=delete(root->right,data);
	 
	 else if(root->data>data)
	 root->left=delete(root->left,data);
	 
	 else
	 {
	 	if(root->left && root->right)
	 	{
	 		temp=max(root->left);
	 		root->data=temp->data;
	 		root->left=delete(root->left,temp->data);
	 		return root;
	 		
		 }
		 else if(root->left)
		 {
		 
		 root=root->left;
		 return root;
	    }
	    else
	    {
	    	root=root->right;
		 return root;
		}
	 }
}
void traverse(struct node *root)
 {
 if(root==NULL)
 return;

 traverse(root->left);
 printf("%d-->",root->data);
 
 traverse(root->right);
 }

int main()
{
	int a[]={10,12,14,2,1,4,17,11,},n,i;
	node *root=NULL;
	n=sizeof(a)/sizeof(a[0]);
	for(i=0;i<n;i++)
	{
		root=insert(root,a[i]);
		
	}
	//printf("%d",max(root->right)->data);
	delete(root,2);
	traverse(root);
return 0;	
	
}
