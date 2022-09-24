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
Position FindPrevious(ElementType X,List L);
void Insert(ElementType X,List L,Position P);


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
   

    // if(Tmp==NULL)
    //     throw "Out of space!!!";

    //能直接赋值，不需要分配内存

    Tmp=L->Next;
    while (Tmp->Element!=X && Tmp!=NULL)
    {
        Tmp=Tmp->Next;
    }
    return Tmp;
}


// If X is not found,return the last

Position FindPrevious(ElementType X,List L)
{
    Position P=L;

    while (P->Next!=NULL && P->Element!=X)
        P=P->Next;
    return P;

}

void Delete(ElementType X,List L)
{
    Position Tmp,PreTmp;
    PreTmp = FindPrevious(X,L);

    //notice IsLast : If X is not found,return the last
    if(!IsLast(PreTmp,L))
    {
        Tmp=PreTmp->Next;
        PreTmp->Next=Tmp->Next;
        free(Tmp);
    }
}

void Insert(ElementType X,List L,Position P)
{
    
}
