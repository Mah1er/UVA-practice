#define ElementType int 
#include<cstdio>
#include<cstdlib>

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X,SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X,SearchTree T);
SearchTree Delete(ElementType X,SearchTree T);
ElementType Retrieve(Position P);

struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};


// 不太确定此处只NULL不赋空的行为
SearchTree MakeEmpty(SearchTree T)
{
    if(T!=NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
}

Position Find(ElementType X,SearchTree T)
{
    if(T==NULL)
        return NULL;
    else if(X < T->Element)
        return Find(X,T->Left);
    else if(X > T->Element)
        return Find(X,T->Right);
    else
        return T;
}

Position FindMax(ElementType X,SearchTree T)
{
    if(T!=NULL)
    {
        while (T->Right!=NULL)
            T=T->Right;
    }
    return T;
}

Position FindMin(ElementType X,SearchTree T)
{
    if(T==NULL)
        return T;
    else if(T->Left==NULL)
        return T;
    else
        return FindMin(X,T->Left);
}

SearchTree Insert(ElementType X,SearchTree T)
{
    if(T==NULL)
    {
        if(T==NULL)
        T=(SearchTree)malloc(sizeof(struct TreeNode));
        if(T==NULL)
            throw "Oou of space";
        else
        {
            T->Element=X;
            T->Left=T->Right=NULL;
        }
    }

    else if (X<T->Element)
        T->Left=Insert(X,T->Left);
    else if (X>T->Element)
        T->Right=Insert(X,T->Right);

    return T;
}

SearchTree Delete(ElementType X,SearchTree T)
{
    Position TmpCell;

    if(T==NULL)
        throw"Element not found";
    
    else if(X<T->Element)
        T->Left=Delete(X,T->Left);
    else if(X>T->Element)
        T->Right=Delete(X,T->Right);

    else if (T->Left && T->Right)
    {
        TmpCell=FindMin(T->Right);
        T->Element=TmpCell->Element;
        T->Right=Delete(T->Element,T->Right);
    }
    else
    {
        TmpCell=T;
        if(T->Left==NULL)
            T=T->Right;
        else if(T->Right==NULL)
            T=T->Left;
        free(TmpCell);
    }
    return T;
}











