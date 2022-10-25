#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxTrees 18

typedef struct BinNode* Position;
typedef struct BinNode* BinTree;
typedef struct Collection* BinQueue;
typedef struct QueueRecord* Queue;

struct BinNode
{
    int value;
    Position LeftChild;
    Position NextSibling;
};

struct QueueRecord
{
    BinTree tree;
    Queue next;
};

struct Collection
{
    int CurrentSize;
    BinTree TheTree[MaxTrees];
};

void Enqueue(Queue head,BinTree T)
{
    Queue p=head->next;
    
    Queue tmp=(Queue)malloc(sizeof(struct QueueRecord));
    tmp->tree=T;
    tmp->next=p;
    head->next=tmp;
}

void Dequeue(Queue head)
{
    Queue p=head->next;
    if(p!=NULL)
        head->next=p->next;
}

BinTree top(Queue head)
{
    return head->next->tree;
}

BinTree CombineTrees(BinTree T1,BinTree T2)
{
    if(T1->value>T2->value)
        return CombineTrees(T2,T1);
    T2->NextSibling=T1->LeftChild;
    T1->LeftChild=T2;
    return T1;
}

BinQueue Merge(BinQueue H1,BinQueue H2)
{
    BinTree T1,T2,Carry=NULL;
    int i,j;

    H1->CurrentSize+=H2->CurrentSize;

    for(i=0,j=1;j<=H1->CurrentSize;i++,j*=2)
    {
        T1=H1->TheTree[i];T2=H2->TheTree[i];

        switch (!!T1+2*!!T2+4*!!Carry)
        {
        case 0: 
            break;
        case 1: 
            break;
        case 2:
            H1->TheTree[i]=T2;
            H2->TheTree[i]=NULL;
            break;
        case 4:
            H1->TheTree[i]=Carry;
            Carry=NULL; 
            break;
        case 3:
            Carry=CombineTrees(T1,T2);
            H1->TheTree[i]=H2->TheTree[i]=NULL;
            break;
        case 5:
            Carry=CombineTrees(T1,Carry);
            H1->TheTree[i]=NULL;
            break;
        case 6:
            Carry=CombineTrees(T2,Carry);
            H2->TheTree[i]=NULL;
            break;
        case 7:
            H1->TheTree[i]=Carry;
            Carry=CombineTrees(T1,T2);
            H2->TheTree[i]=NULL;
            break;
        }
    }
    return H1;
}

BinQueue Initialize()
{
    BinQueue Q=(BinQueue)malloc(sizeof(struct Collection));
    Q->CurrentSize=0;
    for(int i=0;i<MaxTrees;i++)
        Q->TheTree[i]=NULL;

    return Q;
}

void Insert(BinQueue Q,int x)
{
    BinQueue tmp=Initialize();
    BinTree T =(BinTree)malloc(sizeof(struct BinNode));
    T->value=x;
    T->LeftChild=T->NextSibling=NULL;
    tmp->TheTree[0]=T;
    tmp->CurrentSize=1;

    Merge(Q,tmp);
}

int isempty(Queue head)
{
    return head->next==NULL;
}

void levelorder(BinTree T,Queue head)
{

    if(T==NULL)
    {
        printf("0");
        return;
    }
    else
    {
        Enqueue(head,T);
        BinTree tmptree;
        
        while (!isempty(head))
        {
            tmptree=top(head);
            Dequeue(head);
            printf("%d,",tmptree->value);
            if(tmptree->LeftChild)
            {
                tmptree=tmptree->LeftChild;
                Enqueue(head,tmptree);
            }
            while (tmptree->NextSibling)
            {
                tmptree=tmptree->NextSibling;
                Enqueue(head,tmptree);
            }
        }
    }

}

int main()
{
    int n;
    char ch;
    char str[256];
    BinQueue Q=Initialize();

    fgets(str,256,stdin);

    for(int i=0;i<strlen(str)-1;i+=2)
    {
        Insert(Q,str[i]-'0');
    }

    int m;
    scanf("%d",&m);

    BinTree T=Q->TheTree[m];

    Queue head=(Queue)malloc(sizeof(struct QueueRecord));
    head->next=NULL;

    levelorder(T,head);

    return 0;
}
