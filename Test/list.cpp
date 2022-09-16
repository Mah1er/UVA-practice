#define ElementType int
#include<stdio.h>
#include<stdlib.h>

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X,List L);
void Delete(ElementType X,List L);
Position FindPrevious(Position P,List L);
void Insert(ElementType X,List L);


struct Node
{
    ElementType Element;
    Position Next;
};


int IsEmpty(List L)
{
    return L->Next==NULL;   
}

int IsLast(Position P,List L)
{
    return P->Next==NULL;
}

Position Find(ElementType X,List L)
{
    Position Tmp;
    Tmp=(Position)malloc(sizeof(struct Node));
    if(Tmp==NULL)
        throw "Out of space!!!";

    //能直接赋值，不需要分配内存

    Tmp=L->Next;
    while (Tmp->Element!=X && Tmp!=NULL)
    {
        Tmp=Tmp->Next;
    }
    return Tmp;
}


