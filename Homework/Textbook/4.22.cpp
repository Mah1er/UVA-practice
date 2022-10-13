#define ELementType int
#include<stdio.h>

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

int Height(Position P);
int Max(int a,int b);

Position DoubleRotateWithLeft(Position K3)
{
    Position K1,K2;
    K1=K3->Left;
    K2=K1->Right;
    K1->Right=K2->Left;
    K3->Left=K2->Right;
    K2->Left=K1;
    K2->Right=K3;

    K1->Height=Max(Height(K1->Left),Height(K1->Right))+1;
    K3->Height=Max(Height(K3->Left),Height(K3->Right))+1;
    K2->Height=Max(K1->Height,K2->Height)+1;

}






