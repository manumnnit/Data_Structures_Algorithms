#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

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
    
    traverse(root->left);
    printf("%d-->",root->data);
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


int main()
{
struct node *root=getnode(1),*root1;
root->left=getnode(2);
root->right=getnode(3);
root->left->left=getnode(4);
root->left->right=getnode(5);
root->right->left=getnode(6);
root->right->right=getnode(7);
traverse(root);
printf("\n");
return 0;
}
