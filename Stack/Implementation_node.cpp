// 链表的前端作为栈顶
// Stack S作为头节点,无值,S->Next是栈顶元素
// 检测 + free

#define ElementType int 
#include<stdio.h>
#include<stdlib.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;


// 对于每个参数含S的函数，函数实现开头都可以先对S进行检测
// 有关删除的函数 都要考虑free

int IsEmpty(Stack S);
Stack CreateStack();
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X,Stack S);
ElementType Top(Stack S);
void Pop(Stack S);


struct Node
{
    ElementType Element;
    PtrToNode Next;
};

int IsEmpty(Stack S)
{
    return S->Next==NULL;
}

Stack CreateStack()
{
    Stack S=(Stack)malloc(sizeof(Stack));
    if(S==NULL)
        throw "Out of space!!!";
    S->Next=NULL;
    MakeEmpty(S);
    return S;
}

void MakeEmpty(Stack S)
{
    if(S==NULL)
        throw "Must use CreateStack first!!!";
    else
        while (!IsEmpty(S))
            Pop(S);       
}

void Push(ElementType X,Stack S)
{
    PtrToNode TmpCell=(PtrToNode)malloc(sizeof(PtrToNode));
    if(TmpCell==NULL)
        throw "Out of space!!!";
    else
    {
        TmpCell->Element=X;
        TmpCell->Next=S->Next;
        S->Next=TmpCell;
    }
}

ElementType Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Next->Element;
    else
        throw "Stack is empty";
}

void Pop(Stack S)
{
    if(!IsEmpty(S))
    {  
        PtrToNode TmpCell=S->Next;
        S->Next=S->Next->Next;
        free(TmpCell);
    }
    else
        throw "Stack is empty";
}