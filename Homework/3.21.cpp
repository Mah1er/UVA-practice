#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ELementType int
#define EmptyTOS1 -1

struct StackRecord
{
    int Capacity;
    int Top1;
    int Top2;
    ELementType* Array;
};

typedef StackRecord* Stack;

Stack CreateStack(int Capacity);
void DisposeStack(Stack S);

bool IsFull(Stack S);
bool IsEmpty(Stack S,int index);

void Push(Stack S,ELementType X,int index);
void Pop(Stack S,ELementType X,int index);

Stack CreateStack(int Capacity)
{
    Stack S;
    S=(Stack)malloc(sizeof(StackRecord));

    if(S==NULL)
        throw "Out of space!!";

    S->Array=(ELementType*)malloc(sizeof(ELementType)*Capacity);

    if(S->Array==NULL)
        throw "Out of space!!";

    S->Capacity=Capacity;
    S->Top1=EmptyTOS1;
    S->Top2=Capacity;

    return S;
}

void DisposeStack(Stack S)
{
    if(S!=NULL)
    {
        free(S->Array);
        free(S);
    }
}


bool IsFull(Stack S)
{
    return (S->Top1+1)==S->Top2;
}


//index==0:top1
//index==1:top2
bool IsEmpty(Stack S,int index)
{
    if(index==0)
        return S->Top1==EmptyTOS1;

    if(index==1)
        return S->Top2==S->Capacity;
}


void Push(Stack S,ELementType X,int index)
{
    if(IsFull(S))
        throw "Stack Full";

    if(index==0)
    {
        S->Array[++S->Top1]=X;
    }
    else if(index==1)
    {
        S->Array[--S->Top2]=X;
    }
}


void Pop(Stack S,int index)
{
    if(IsEmpty(S,index))
        throw "Stack Empty";

    if(index==0)
        S->Top1--;
    
    else if(index==1)
        S->Top2++;
}

void PrintList(Stack S)
{
    for(int i=0;i<S->Capacity;i++)
        printf("%d ",S->Array[i]);
    printf("\n");
}



void test()
{
    Stack S=CreateStack(10);

    for(int i=0;i<S->Capacity;i++)
        S->Array[i]=0;

    PrintList(S);

    Push(S,1,0);
    PrintList(S);
    Push(S,1,1);
    PrintList(S);
    Pop(S,0);
    PrintList(S);
    Pop(S,1);
    PrintList(S);
    Push(S,2,1);
    Push(S,2,0);
    PrintList(S);    
}


int main()
{
    test();
    return 0;
}