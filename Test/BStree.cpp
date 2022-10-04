#include<stdio.h>
#include<stdlib.h>
#define ElementType int

struct TreeNode;
typedef TreeNode* Position;
typedef TreeNode* SearchTree;

void MakeEmpty(SearchTree T);
Position Find(ElementType X,SearchTree T);
Position FindMax(SearchTree T);
Position FindMin(SearchTree T);
SearchTree Insert(ElementType X,SearchTree T);
SearchTree Delete(ElementType X,SearchTree T);
ElementType Retrive(Position P);

struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

//遍历整棵树 后序free
void MakeEmpty(SearchTree T)
{
    if(T!=NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return;
}

Position Find(ElementType X,SearchTree T)
{
    //注意处理空树这种退化情况

    if(T==NULL)
        return NULL;

    if(X<T->Element)
        return Find(X,T->Left);
    
    else if (X>T->Element)
        return Find(X,T->Right);
    
    else
        return T;
}

//?????????????????????????????????????????


Position FindMin(SearchTree T)
{
    SearchTree Tmp=T;
    
    while(Tmp->Left!=NULL)
        Tmp=Tmp->Left;

    return Tmp;
}

//?????????????????????????????????????????

/*

如果采用递归，注意空树这种退化情况！！

Position FindMin(SearchTree T)
{
    if(T==NULL)
        return NULL;
    else if(T->Left==NULL)
        return T;
    else
        return FindMin(T->Left);
}

*/


SearchTree Insert(ElementType X, SearchTree T)
{

    if (T == NULL)
    {
        T = (SearchTree)malloc(sizeof(TreeNode));

        if (T == NULL)
            throw "Out of space!!!";

        else
        {
            T->Element = X;
            T->Left = NULL;
            T->Right = NULL;
        }
    }

    else if (X < T->Element)
        T->Left = Insert(X, T->Left);

    else if (X > T->Element)
        T->Right = Insert(X, T->Right);

    return T;
}


SearchTree Delete(ElementType X,SearchTree T)
{
    Position TmpCell;

    if(T==NULL)
        throw "Element not found!!!";
    
    else if (X<T->Element)
        T->Left=Delete(X,T->Left);
    
    else if(X>T->Element)
        T->Right=Delete(X,T->Right);
    
    else if(T->Left && T->Right)
    {
        TmpCell=FindMin(T->Right);
        T->Element=TmpCell->Element;
        T->Right=Delete(T->Element,T->Right);
    }

    else
    {
        TmpCell = T;
        if(T->Left==NULL)
            T=T->Right;
        else if(T->Right)
            T=T->Right;
        free(TmpCell);
    }
    return T;
}

