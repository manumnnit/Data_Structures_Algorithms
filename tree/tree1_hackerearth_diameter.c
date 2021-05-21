/*
Given a binary tree which has T

nodes, you need to find the diameter of that binary tree. The diameter of a tree is the number of nodes on the longest path between two leaves in the tree.

Input:
First line contains two integers, T
and X, number of nodes in the tree and value of the root.
Next 2×(T-1)

lines contain details of nodes.
Each detail of node contains two lines. First lines contains a string and second line contains an integer, which denotes the path of the node and the value of the node respectively.

String consists of only L
or R. L denotes left child and R

denotes right child. ( Look at the sample explanation for more details )

Output:
Print the diameter of the binary tree.

Constraints:
1=T=20

1=valueofnodes=20

*/


//incomplete program





#include <stdio.h>
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
    printf("%d-->",root->data);
    traverse(root->left);
    traverse(root->right);
}

int main()
{
    int T,i,val;
    struct node *root,*temp;
    char *pos;
    scanf("%d%d",&T,&val);
    root=getnode(val);
    for(i=1;i<T;i++)
    {
        temp=root;
        scanf("%s",pos);
        printf("%s\n",pos);
        while(*(pos+1)!='\0')
        {
            if(*pos=='L')
            temp=temp->left;
            else if(*pos=='R')
            temp=temp->right;
        }
        scanf("%d",&val);
        if(*pos=='L')
        temp->left=getnode(val);
        else if(*pos=='R')
        temp->right=getnode(val);
        
    }
    
    traverse(root);
    return 0;
}

