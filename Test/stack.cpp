#include<stdio.h>
#include<stdlib.h>

#define ElementType int
#define EmptyTOS -1
#define MinCapacity 5


// 1. 声明结构体malloc,free的时候也要判断是否为NULL
// 2. Push 和 Pop的时候注意错误检测 

struct StackRecord;
typedef StackRecord *Stack;

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType* Array;
};

int IsFull(Stack S);
int IsEmpty(Stack S);

Stack CreateStack(int Capacity);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(Stack S,ElementType X);
ElementType Pop(Stack S);
ElementType Top(Stack S);


Stack CreateStack(int Capacity)
{
    //需要malloc

    if(Capacity<MinCapacity)
        throw "Capacity too small!!!";

    Stack S;
    S=(Stack)malloc(sizeof(StackRecord));

    if(S==NULL)
        throw "Out of space!!!";
    
    S->Capacity=Capacity;
    S->Array=(ElementType*)malloc(sizeof(ElementType)*Capacity);

    if(S->Array==NULL)
        throw "Out of space!!!";

    MakeEmpty(S);
    return S;

}

void MakeEmpty(Stack S)
{   
    // Empty 用于MakeEmpty(S)
    S->TopOfStack=EmptyTOS;
}


void DisposeStack(Stack S)
{

    if (S!=NULL)
    {
        free(S->Array);
        free(S);
    }
}


int IsEmpty(Stack S)
{
    return S->TopOfStack==EmptyTOS;
}

int IsFull(Stack S)
{
    return S->Capacity==(S->TopOfStack+1);
}


void Push(Stack S,ElementType X)
{
    //每次push或pop都要注意错误判断

    if(!IsFull(S))
        S->Array[++S->TopOfStack] = X;
    else
        throw "Stack already full";
}

ElementType Pop(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack--];
    else
        throw "Empty Stack";
}


ElementType Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack];
    else
        throw "Empty Stack";
}




