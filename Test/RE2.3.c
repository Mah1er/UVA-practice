#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode* AvlTree;

struct TreeNode
{
    int value;
    int height;
    AvlTree left;
    AvlTree right;
};

AvlTree SingleRoateWithLeft(AvlTree T2);
AvlTree SingleRoateWithRight(AvlTree T2);
AvlTree DoubleRoateWithLeft(AvlTree T3);
AvlTree DoubleRoateWithRight(AvlTree T3);

int Height(AvlTree T)
{
    if(T==NULL)
        return -1;
    else
        return T->height;
}

int MAX(int a,int b)
{
    if(a>b) return a;
    else return b;
}

AvlTree Insert(AvlTree T,int x)
{
    if(T==NULL)
    {
        T=(AvlTree)malloc(sizeof(struct TreeNode));
        T->value=x;
        T->height=0;
        T->left=T->right=NULL;
    }
    if(x<T->value)
    {
        T->left=Insert(T->left,x);
        if(Height(T->left)-Height(T->right)==2)
        {
            if(x<T->left->value)
                T=SingleRoateWithLeft(T);
            else if(x>T->left->value)
                T=DoubleRoateWithLeft(T);
        }
    }
    if(x>T->value)
    {
        T->right=Insert(T->right,x);
        if(Height(T->right)-Height(T->left)==2)
        {
            if(x>T->right->value)
                T=SingleRoateWithRight(T);
            else if(x<T->right->value)
                T=DoubleRoateWithRight(T);
        }
    }
    T->height=MAX(Height(T->left),Height(T->right))+1;

    return T;
}

AvlTree SingleRoateWithLeft(AvlTree T2)
{
    AvlTree T1;
    T1=T2->left;
    T2->left=T1->right;
    T1->right=T2;

    T2->height=MAX(Height(T2->left),Height(T2->right))+1;
    T1->height=MAX(Height(T1->left),Height(T1->right))+1;

    return T1;
}

AvlTree DoubleRoateWithLeft(AvlTree T3)
{
    T3->left=SingleRoateWithRight(T3->left);
    return SingleRoateWithLeft(T3);
}

AvlTree SingleRoateWithRight(AvlTree T2)
{
    AvlTree T1;
    T1=T2->right;
    T2->right=T1->left;
    T1->left=T2;

    T2->height=MAX(Height(T2->left),Height(T2->right))+1;
    T1->height=MAX(Height(T1->left),Height(T1->right))+1;

    return T1;
}

AvlTree DoubleRoateWithRight(AvlTree T3)
{
    T3->right=SingleRoateWithLeft(T3->right);
    return SingleRoateWithRight(T3);
}

void Preorder(AvlTree T)
{
    if(T!=NULL)
    {
        printf("%d,",T->value);

        if(T->left) Preorder(T->left);
        if(T->right) Preorder(T->right);
    }

}

int main()
{
    int n;
    char ch;

    AvlTree T=NULL;

    while (scanf("%d",&n)==1)
    {
        scanf("%c",&ch);
        T=Insert(T,n);
    }
    Preorder(T);    


    return 0;
}




