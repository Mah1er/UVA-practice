#include<stdio.h>
#include<stdlib.h>

struct linknode
{
    int value;
    struct linknode* next;
};

typedef struct linknode* ptrtolink;
typedef ptrtolink pos;

ptrtolink linkReverse(pos head)
{
    pos newhead,nextnewhead,tmpp;
    newhead=(pos)malloc(sizeof(struct linknode));

    if(newhead==NULL)
        throw "Out of space!!!";
    
    newhead->next=NULL;

    ptrtolink p=head->next;

    while (p!=NULL)
    {
        pos tmp;
        tmp=(pos)malloc(sizeof(struct linknode));

        if(tmp==NULL)
            throw "Out of space!!!";

        nextnewhead=newhead->next;
        tmp->value=p->value;
        tmp->next=nextnewhead;
        newhead->next=tmp;
        tmpp=p;
        p=p->next;
        free(tmpp);
    }
    return newhead;
}

void printlink(pos head)
{
    pos p=head->next;
    printf("The list is:");
    while (p!=NULL)
    {
        printf(" %d",p->value);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    pos head,p1,p2,p3,p4;
    head=(pos)malloc(sizeof(struct linknode));
    p1=(pos)malloc(sizeof(struct linknode));
    p2=(pos)malloc(sizeof(struct linknode));
    p3=(pos)malloc(sizeof(struct linknode));
    p4=(pos)malloc(sizeof(struct linknode));

    head->next=p1;
    p1->next=p2;
    p2->next=p3;
    p3->next=p4;
    p4->next=NULL;
    p1->value=1;
    p2->value=2;
    p3->value=3;
    p4->value=4;

    printlink(head);
    pos newhead=linkReverse(head);
    printlink(newhead);


}


