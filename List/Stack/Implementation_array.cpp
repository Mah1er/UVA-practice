// capacity + topofstack
// "stack is empty" means topofstack is emptytos but not capacity is zero
#define ElementType int
#define EmptyTOS 0
#include<stdio.h>
#include<stdlib.h>


struct StackRecord;
typedef struct StackRecord* Stack;

int IsEmpty(Stack S);
int IsFUll(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X,Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);


struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType* Array;
};

Stack CreateStack(int MaxElements)
{
    Stack S=(StackRecord*)malloc(sizeof(StackRecord*));
    if(S==NULL)
        throw "Out of space!!!";
    S->Capacity=MaxElements;
    S->Array=(ElementType*)malloc(sizeof(ElementType)*MaxElements);

    MakeEmpty(S);// 创建时赋值为空        
    return S;
}

void MakeEmpty(Stack S)
{
    S->TopOfStack=EmptyTOS;
}

int IsEmpty(Stack S)
{
    return S->TopOfStack==EmptyTOS;
}

void Push(ElementType X,Stack S)
{
    if(IsFUll(S))
        throw "Stack is FULL";
    else
        S->Array[++S->TopOfStack]=X;
}

void Pop(Stack S)
{
    if(IsEmpty(S))
        throw "Stack is empty";
    else
        S->TopOfStack--;  
}

ElementType TopAndPop(Stack S)
{
    if(IsEmpty(S))
        throw "Stack is empty";
    else
    {
        ElementType Tmp=S->Array[S->TopOfStack];
        S->TopOfStack--;
        return Tmp;
    }
}

ElementType Top(Stack S)
{
    if(IsEmpty(S))
        throw "Stack is empty";
    else
        return S->Array[S->TopOfStack];
}

