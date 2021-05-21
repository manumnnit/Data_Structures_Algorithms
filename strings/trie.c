#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct trienode
{
	struct trienode *child[26];
	int isleaf;
} node;

int chartoindex(char c)
{
	return ((int)c-(int)'a');
}

node* getNode()
{
	node *newnode=(node*)malloc(sizeof(node));
	int i=0;
	if(!newnode)
	{
		printf("memory error\n");
		return NULL;
	}
	newnode->isleaf=0;
	for(i=0;i<26;i++)
	newnode->child[i]=NULL;
	
	return newnode;
}

void insert(node *root,char *key)
{
	node *temp;
	int level,length,index;
	length=strlen(key);
	//if(!root)
	//root=getnode();
	temp=root;
	for(level=0;level<length;level++)
	{
		index=chartoindex(key[level]);
		if(temp->child[index]==NULL)
		temp->child[index] =getNode();
		temp=temp->child[index];
	}
	
	temp->isleaf=1;
}

int search(node *root,char *key)
{
     node *temp;
	int level,length,index;
	length=strlen(key);
	//if(!root)
	//root=getnode();
	temp=root;
	for(level=0;level<length;level++)
	{
		index=chartoindex(key[level]);
		if(temp->child[index]==NULL)
		return 0;
		temp=temp->child[index];
	}
	
	if(temp!=NULL && temp->isleaf==1)
	return 1;	
	else 
	return 0;
}


// Driver
int main()
{
    // Input keys (use only 'a' through 'z' and lower case)
    char keys[][8] = {"the", "a", "there", "answer", "any",
    "by", "bye", "their","thor"};
 
    char output[][32] = {"Not present in trie", "Present in trie"};
 
 
    node *root = getNode();
 
    // Construct trie
    int i,ARRAY_SIZE=sizeof(keys)/sizeof(keys[0]);
    for (i = 0; i < ARRAY_SIZE; i++)
       insert(root, keys[i]);
 
    // Search for different keys
    printf("%s --- %s\n", "there", output[search(root, "there")] );
    printf("%s --- %s\n", "these", output[search(root, "these")] );
    printf("%s --- %s\n", "their", output[search(root, "their")] );
    printf("%s --- %s\n", "thaw", output[search(root, "thaw")] );
 
    return 0;
}  
