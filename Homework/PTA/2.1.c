#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;

typedef struct QueueRecord* Queue;


struct TreeNode
{
    int key;
    Position left;
    Position right;
};

struct QueueRecord
{
    SearchTree tree;
    Queue next; 
};

void Enqueue(Queue head,SearchTree T)
{
    Queue tmp;
    tmp=(Queue)malloc(sizeof(struct QueueRecord));

    tmp->tree=T;

    while (head->next!=NULL)
    {
        head=head->next;
    }

    head->next=tmp;
    tmp->next=NULL;   

}

Queue Dequeue(Queue head)
{
    Queue tmp;

    if(head->next!=NULL)
    {
        tmp=head->next;
        head->next=tmp->next;
        return tmp;
    }
}


Position Insert(SearchTree T,int x)
{

    if(T==NULL)
    {
        T=(SearchTree)malloc(sizeof(struct TreeNode));
        T->key=x;
        T->left=T->right=NULL;
    }

    else if(x<T->key)
        T->left=Insert(T->left,x);
    else if(x>T->key)
        T->right=Insert(T->right,x);
    
    return T;
}

int main()
{
    int n,m;
    SearchTree T=NULL;
    
    scanf("%d",&n);    

    //建树
    for(int i=0;i<n;i++)
    {
        scanf("%d,",&m);
        T=Insert(T,m);
    }

    
    int count;
    scanf("%d",&count);

    Queue Q=(Queue)malloc(sizeof(struct QueueRecord));
    Q->next=NULL;

    Enqueue(Q,T);

    for(int i=1;i<count;i++)
    {
        int times=1;
        for(int j=1;j<i;j++)
            times*=2;
        
        for(int j=0;j<times;j++)//找到对应的层
        {
            Queue member=Dequeue(Q);
            SearchTree tmp=member->tree;

            if(tmp==NULL)
            {
                Enqueue(Q,NULL);
                Enqueue(Q,NULL);                
            }

            else
            {
                Enqueue(Q,tmp->left);
                Enqueue(Q,tmp->right);
            }

        }

    }

    Queue order=Q->next;
    int error=1;

    while (order!=NULL)
    {
        if(order->tree!=NULL)
        {
            printf("%d,",order->tree->key);
            error=0;        
        }
        order=order->next;
    }
    
    if(error)
        printf("-1");

    printf("\n");
    return 0;

}




