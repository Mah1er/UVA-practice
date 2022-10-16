#define ELementType int
#include<stdio.h>
#include<stdlib.h>


struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

struct AvlNode
{
    ELementType ELement;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

static int Height(Position P);
static Position SingleRotateWithLeft(Position K2);
static Position DoubleRotateWithLeft(Position K3);
static Position SingleRotateWithRight(Position K2);
static Position DoubleRotateWithRight(Position K3);

static int Height(Position P)
{
    if(P==NULL)
        return -1;
    else
        return P->Height;
}

int Max(int a,int b)
{
    if (a>b)
        return a;
    return b;
    
}


AvlTree Insert(ELementType X,AvlTree T)
{
    if(T==NULL)
    {
        T=(AvlTree)malloc(sizeof(struct AvlNode));

        
        T->ELement=X;
        T->Height=0;
        T->Left=NULL;
        T->Right=NULL;
        
    }

    else if(X<T->ELement)
    {
        T->Left=Insert(X,T->Left);
        if(Height(T->Left)-Height(T->Right)==2)
        {
            if(X < T->Left->ELement)
                T=SingleRotateWithLeft(T);
            else if(X > T->Left->ELement)
                T=DoubleRotateWithLeft(T);
        }
    }
    else if (X>T->ELement)
    {
        T->Right=Insert(X,T->Right);
        if(Height(T->Right)-Height(T->Left)==2)
        {
            if(X > T->Right->ELement)
                T=SingleRotateWithRight(T);
            else if(X < T->Right->ELement)
                T=DoubleRotateWithRight(T);
        }
    }
    T->Height=Max(Height(T->Left),Height(T->Right))+1;
    return T;
}

static Position SingleRotateWithLeft(Position K2)
{
    Position K1;
    K1=K2->Left;
    K2->Left=K1->Right;
    K1->Right=K2;

    K2->Height=Max(Height(K2->Left),Height(K2->Right))+1;
    K1->Height=Max(Height(K1->Left),K2->Height)+1;

    return K1;
}


static Position DoubleRotateWithLeft(Position K3)
{
    K3->Left=SingleRotateWithRight(K3->Left);
    return SingleRotateWithLeft(K3);
}

static Position SingleRotateWithRight(Position K1)
{
    Position K2;
    K2=K1->Right;
    K1->Right=K2->Left;
    K2->Left=K1;

    K2->Height=Max(Height(K2->Left),Height(K2->Right))+1;
    K1->Height=Max(Height(K1->Left),K2->Height)+1;

    return K2;
}


static Position DoubleRotateWithRight(Position K3)
{
    K3->Right=SingleRotateWithLeft(K3->Right);
    return SingleRotateWithRight(K3);
}



void Preorder(AvlTree T)
{
    if(T!=NULL)
        printf("%d,",T->ELement);
    if(T->Left) Preorder(T->Left);
    if(T->Right) Preorder(T->Right);

}


int main()
{
    int m;
    char ch;

    AvlTree T=NULL;

    while (scanf("%d",&m)==1)
    {
        scanf("%c",&ch);
        T=Insert(m,T);
    }
    
    Preorder(T);
    printf("\n");

    return 0;
}
