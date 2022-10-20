#include<stdio.h>
#include<stdlib.h>

int flag=0;

typedef struct TreeNode* SearchTree;

struct TreeNode
{
    int depth;
    int value;
    SearchTree left;
    SearchTree right;
};

SearchTree Insert(SearchTree T,int x)
{
    if(T==NULL)
    {
        T=(SearchTree)malloc(sizeof(struct TreeNode));
        T->value=x;
        T->left=T->right=NULL;
    }
    else if(T->value==-1)
        T->value=x;

    else if(x<T->value)
    {
        T->left=Insert(T->left,x);
        T->left->depth=T->depth+1;
    }
    else if(x>T->value)
    {
        T->right=Insert(T->right,x);
        T->right->depth=T->depth+1;
    }


    return T;
}

void Preorder(SearchTree T,int level)
{
    if(T!=NULL)
    {
        if(T->depth==level)
        {
            printf("%d,",T->value);
            flag=1;
        }
        if(T->left) Preorder(T->left,level);
        if(T->right) Preorder(T->right,level);
    }
}


int main()
{
    int n;
    scanf("%d",&n);

    int m;

    SearchTree T=(SearchTree)malloc(sizeof(struct TreeNode));
    T->value=-1;
    T->depth=1;
    T->left=T->right=NULL;

    for(int i=0;i<n;i++)
    {
        scanf("%d,",&m);
        T=Insert(T,m);
    }

    int level;
    scanf("%d",&level);

    Preorder(T,level);
    if(!flag)
        printf("-1");
    printf("\n");

    return 0;
}



