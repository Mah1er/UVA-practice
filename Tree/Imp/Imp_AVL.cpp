// 单双旋转的本质都是换根节点(此根节点可以是更大的树的儿子)
// 需要更换的根节点是插入之后、未旋转前、不平衡的包含该根节点的最小树
// 根据插入的位置(左左or右右)(左右or右左)确定是单旋转还是双旋转
// 单旋转 根节点换成子节点
// 双旋转 根节点换成子节点的子节点
// 插哪换哪

#define ELementType int
#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;


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

AvlTree Insert(ELementType X,AvlTree T)
{
    if(T==NULL)
    {
        T=(AvlTree)malloc(sizeof(struct AvlNode));
        if(T==NULL)
            throw "Out of space";
        else
        {
            T->ELement=X;
            T->Height=0;
            T->Left=NULL;
            T->Right=NULL;
        }
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
    T->Height=max(Height(T->Left),Height(T->Right))+1;
    return T;
}


static Position SingleRotateWithLeft(Position K2)
{
    Position K1;
    K1=K2->Left;
    K2->Left=K1->Right;
    K1->Right=K2;

    K2->Height=max(Height(K2->Left),Height(K2->Right))+1;
    K1->Height=max(Height(K1->Left),K2->Height)+1;

    return K1;
}


static Position DoubleRotateWithLeft(Position K3)
{
    K3->Left=SingleRotateWithRight(K3->Left);
    return SingleRotateWithLeft(K3);
}

