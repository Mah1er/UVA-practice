#define ELementType int

#include<stdio.h>
#include<stdlib.h>

typedef struct BSTNode* Position;
typedef struct BSTNode* SearchTree;

struct BSTNode
{
    ELementType ELement;
    SearchTree Left;
    SearchTree Right;
};

void MakeEmpty(SearchTree root);
SearchTree Insert(SearchTree root,ELementType x);
SearchTree Delete(SearchTree root,ELementType x);
Position FindMin(SearchTree root);

void MakeEmpty(SearchTree root)
{
    if(root!=NULL)
    {
        MakeEmpty(root->Left);
        MakeEmpty(root->Right);
        free(root);
    }
    return;
}

SearchTree Insert(SearchTree root,ELementType x)
{
    SearchTree tmp;

    if(root==NULL)
    {
        tmp=(SearchTree)malloc(sizeof(struct BSTNode));
        tmp->Left=tmp->Right=NULL;
    }

    else if(x<root->ELement)
    {
        root->Left=Insert(root->Left,x);
    }
    else if(x>root->ELement)
    {
        root->Right=Insert(root->Right,x);
    }

    return root;
}

SearchTree Delete(SearchTree root,ELementType x)
{
    SearchTree tmp;
    
    if(x<root->ELement)
    {
        root->Left=Delete(root->Left,x);
    }
    else if(x>root->ELement)
    {
        root->Right=Delete(root->Right,x);
    }

    if(x==root->ELement)
    {
        if(root->Left&&root->Right)
        {
            tmp=FindMin(root->Right);
            root=Delete(root,tmp->ELement);
            root->ELement=tmp->ELement;

            return root;//
        }
        else
        {
            tmp=root;
            if(root->Left==NULL)
                root=root->Right;
            else if(root->Left==NULL)
                root=root->Left;

            free(tmp);

        }

    }

    return root;
}








