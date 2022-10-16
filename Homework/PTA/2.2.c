#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;

typedef struct QueueRecord* Queue;


struct TreeNode
{
    int key;
    Position left;
    Position right;
};

Position Insert(SearchTree T,int x)
{

    if(T==NULL)
    {
        T=(SearchTree)malloc(sizeof(struct TreeNode));
        T->key=x;
        T->left=T->right=NULL;
    }

    else if(x<T->key)
        T->left=Insert(T->left,x);
    else if(x>T->key)
        T->right=Insert(T->right,x);
    
    return T;
}

void Preorder(SearchTree T)
{
    
    printf("%d,",T->key);

    if(T->left!=NULL) Preorder(T->left);
    if(T->right!=NULL) Preorder(T->right);
}

int main()
{
    SearchTree T=NULL;

    int m;
    char ch;
    int i=0;

    //建树
    while (scanf("%d",&m)==1)
    {

        scanf("%c",&ch);
        T=Insert(T,m);
    }
    
    Preorder(T);
    printf("\n");
    return 0;
}
