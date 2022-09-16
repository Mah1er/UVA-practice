#include<stdio.h>
#include<stdlib.h>

struct PolyNode;
typedef struct PolyNode* PolyList;

struct PolyNode
{
    int coe;
    int exp;
    PolyList next;
};

PolyList CreatePoly(int n)
{
    PolyList head=(PolyList)malloc(sizeof(struct PolyNode));
    
    if(head==NULL)
        throw "Out of space!!!";
    
    PolyList P= head;
    P->next=NULL;

    int coe,exp;
    while (n--)
    {
        printf("Please input ceo and exp in pairs.\n");
        scanf("%d%d",&coe,&exp);

        PolyList tmp=(PolyList)malloc(sizeof(struct PolyNode));
    
        if(tmp==NULL)
            throw "Out of space!!!";

        tmp->coe=coe;
        tmp->exp=exp;
        P->next=tmp;
        P=P->next;
    }
    P->next=NULL;
    return head;
}

PolyList Add(PolyList L1,PolyList L2)
{
    PolyList head=CreatePoly(0);
    PolyList P= head;   
    PolyList p1=L1,p2=L2;

    int carry=0;
    int sum;
    int maxemp=0;

    while (p1!=NULL && p2!=NULL)
    {
        PolyList tmp=(PolyList)malloc(sizeof(struct PolyNode));
    
        if(tmp==NULL)
            throw "Out of space!!!";

        sum=p1->coe+p2->coe+carry;
        tmp->coe=sum % 10;
        carry=sum /10;


        if(p1->exp==p2->exp)
            tmp->exp=p1->exp;
        else
            throw "Unknow error!!!";

        P->next=tmp;
        P=P->next;


        p1=p1->next;
        p2=p2->next;
        maxemp++;
    }
    
    if(p1==NULL)
    {
        while (p2!=NULL)
        {
            PolyList tmp=(PolyList)malloc(sizeof(struct PolyNode));
            if(tmp==NULL)
                throw "Out of space!!!";

            sum=p2->coe+carry;
            tmp->coe=sum % 10;

            tmp->exp=p2->exp;
    
            carry=sum /10;
            P->next=tmp;
            P=P->next;
            maxemp++;
        }
        
        if (carry)
        {
            PolyList tmp=(PolyList)malloc(sizeof(struct PolyNode));
    
            if(tmp==NULL)
                throw "Out of space!!!";

            tmp->coe=carry;
            tmp->exp=P->exp+1;
            P->next=tmp;
            P=P->next;
        }
    }


    if(p2==NULL)
    {
        while (p1!=NULL)
        {
            PolyList tmp=(PolyList)malloc(sizeof(struct PolyNode));
            if(tmp==NULL)
                throw "Out of space!!!";

            sum=p1->coe+carry;
            tmp->coe=sum % 10;

            tmp->exp=p1->exp;
    
            carry=sum /10;
            P->next=tmp;
            P=P->next;
            maxemp++;
        }
        
        if (carry)
        {
            PolyList tmp=(PolyList)malloc(sizeof(struct PolyNode));
    
            if(tmp==NULL)
                throw "Out of space!!!";

            tmp->coe=carry;
            tmp->exp=P->exp+1;
            P->next=tmp;
            P=P->next;
        }
    }

    P->next=NULL;

    return head;
}


int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    PolyList M=CreatePoly(m);
    PolyList N=CreatePoly(n);
    PolyList SUM=Add(M,N);

    return 0;
}


