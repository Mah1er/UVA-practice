#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10
#define ElementType int 


struct DequeRecord
{
    int Front;
    int Rear;
    int Size;
    int Capacity;
    ElementType* Array;
};

typedef DequeRecord* Deque;


Deque CreateDeque(int Capacity);
void DisposeDeque(Deque Q);

bool IsFull(Deque Q);
bool IsEmpty(Deque Q);

int Succ(Deque Q);

void Push(ElementType X,Deque Q);
ElementType Pop(Deque Q);
void Inject(ElementType X,Deque Q);
ElementType Eject(Deque Q);


Deque CreateDeque(int Capacity)
{
    Deque Q;
    Q=(Deque)malloc(sizeof(DequeRecord));

    if(Q==NULL)
        throw "Out of space!!";

    Q->Array=(ElementType*)malloc(sizeof(ElementType)*Capacity);

    if(Q->Array==NULL)
        throw "Out of space!!";
    
    Q->Front=Q->Rear=0;
    Q->Capacity=Capacity;
    Q->Size=0;

    return Q;
}


void DisposeDeque(Deque Q)
{
    if(Q!=NULL)
    {
        free(Q->Array);
        free(Q);
    }
}


bool IsFull(Deque Q)
{
    return Q->Size==Q->Capacity;
}

bool IsEmpty(Deque Q)
{
    return Q->Size==0;
}


int Succ(int Value,Deque Q)
{
    if(++Value==Q->Capacity)
        Value=0;
    return Value;
}

int Prev(int Value,Deque Q)
{
    if(--Value==-1)
        Value=Q->Capacity-1;
    return Value;
}

void Push(ElementType X,Deque Q)
{
    if(IsFull(Q))
        throw "Deque Full";

    else if (IsEmpty(Q))
    {
        Q->Array[Q->Front]=X;
        Q->Size++;    
    }
    
    else
    {
        Q->Front=Prev(Q->Front,Q);
        Q->Array[Q->Front]=X;
        Q->Size++;
    }

    return;
}



ElementType Pop(Deque Q)
{
    ElementType X;

    if(IsEmpty(Q))
        throw "Deque Empty";

    else
    {
        X=Q->Array[Q->Front];
        Q->Front=Succ(Q->Front,Q);
        Q->Size--;
    }
    return X;
}



void Inject(ElementType X,Deque Q)
{

    if(IsFull(Q))
        throw "Deque Full";

    else if (IsEmpty(Q))
    {
        Q->Array[Q->Rear]=X;
        Q->Size++;
    }
    
    else
    {
        Q->Rear=Succ(Q->Rear,Q);
        Q->Array[Q->Rear]=X;
        Q->Size++;
    }

    return;

}


ElementType Eject(Deque Q)
{
    ElementType X;

    if(IsEmpty(Q))
        throw "Deque Empty";
    else
    {
        X=Q->Array[Q->Rear];
        Q->Rear=Prev(Q->Rear,Q);
        Q->Size--;
    }        
    return X;
}



void PrintList(Deque Q)
{
    for(int i=0;i<Q->Capacity;i++)
        printf("%d ",Q->Array[i]);
    printf("\n");

    printf("front:%d rear:%d size:%d\n",Q->Front,Q->Rear,Q->Size);

    return;
}


void test()
{
    Deque Q=CreateDeque(10);

    for(int i=0;i<10;i++)
        Q->Array[i]=0;
    
    Push(1,Q);
    Push(2,Q);
    Push(3,Q);
    
    PrintList(Q);
    
    Pop(Q);Push(4,Q);
    PrintList(Q);

    Eject(Q);
    PrintList(Q);

    Inject(5,Q);
    PrintList(Q);

}

int main()
{
    test();
    return 0;
}