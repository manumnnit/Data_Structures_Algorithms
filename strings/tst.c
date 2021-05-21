//ternary search tree
//pending code
//wrong program
#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct tstnode
{
	char data;
	struct tstnode *left,*eq,*right;
	int isleaf;
} node;


node* getnode(char c)
{
	node *newnode=(node*)malloc(sizeof(node));
	
	if(!newnode)
	{
		printf("memory error\n");
		return NULL;
	}
	newnode->data=c;
	newnode->eq=newnode->left=newnode->right=NULL;
	newnode->isleaf=0;
	
	return newnode;
}

node* insert(node *root,char *key)
{
	if(!root)
	{
		root=getnode(*key);
		printf("%c",*key);
		
	}
	
	if(root->data>*key)
	{
		root->left=insert(root->left,key);
	}
	else if(root->data<*key)
	root->right=insert(root->right,key);
	else
	{
    if(key+1)
    root->eq=insert(root->eq,key+1);
    else
	root->isleaf=1;	
	
   }

}

int search(node *root,char *key)
{
	if(!root)
	return 0;
 if(root->data>*key)
	{
		return search(root->left,key);
	}
	else if(root->data<*key)
	return search(root->right,key);
	else
	{
	if(*(key+1)=='\0')
	return root->isleaf;
	 
	 return search(root->eq,key+1);
    }
   
}


// Driver
int main()
{
   
 
 node *root=NULL;
  root=insert(root,"cat");
   root=insert(root,"cats");root=insert(root,"up");
   root=insert(root,"bug");
    
 
   search(root,"bug")?printf("found"):printf("not found");
   
    return 0;
}
