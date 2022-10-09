#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct listnode* list;

struct listnode
{
    int value;
    list next;
};

list prelist(list l)
{
    list p=l;
    while (p->next!=l)
    {
        p=p->next;
    }
    return p;
}

int main()
{
    int m,n;
    scanf("%d,%d",&m,&n);

    int ans[100];
    int count=0;

    list head=(list)malloc(sizeof(struct listnode));
    head->value=1;
    head->next=NULL;

    list p = head;

    for(int i=2;i<=m;i++)
    {
        list tmp=(list)malloc(sizeof(struct listnode));
        tmp->value=i;
        p->next=tmp;
        p=p->next;
    }

    p->next=head;

    list l=head;

    while (l->next!=l)
    {
        for(int i=0;i<n;i++)
        {
            l=l->next;
        }
        ans[count++]=l->value;
        list prel=prelist(l);
        prel->next=l->next;
        l=prel->next;
    }

    ans[count++]=l->value; 

    printf("%d",ans[0]);
    for(int i=1;i<count;i++)
        printf(",%d",ans[i]);
    printf("\n");

}