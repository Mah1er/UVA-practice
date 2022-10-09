#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int id;
    struct Node* next;
};


typedef struct Node* position;

position CreateCircle(int n)
{
    position head;
    head=(position)malloc(sizeof(struct Node));

    if(head==NULL)
        throw "Out of space!!!";

    head->id=1;
    position p =head;

    for(int i=2;i<=n;i++)
    {
        position tmp;
        tmp=(position)malloc(sizeof(struct Node));

        if(tmp==NULL)
            throw "Out of space!!!";

        tmp->id=i;
        p->next=tmp;
        p=p->next;
    }
    p->next=head;
    return head;
}

position prepos(position p)
{
    position tmp=p;
    while (tmp->next!=p)
    {
        tmp=tmp->next;
    }
    return tmp;
}

int solve(position head,int M)
{
    int times;
    position p=head;

    while (p!=p->next)
    {   
        times=M;
        while(times--)
        {
            p=p->next;
        }
        position prep=prepos(p);
        prep->next=p->next;

        position tmp=p;
        p=prep->next;
        free(tmp);
    }
    return p->id;
}

int main()
{
    int M,n;
    scanf("%d%d",&M,&n);
    position head=CreateCircle(n);
    int ans=solve(head,M);
    printf("The answer is %d\n",ans);

    return 0;
}


