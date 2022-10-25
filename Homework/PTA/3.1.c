#include<stdio.h>
#include<stdlib.h>

typedef struct HeapRecord* PriorityQueue;

struct HeapRecord
{
    int capacity;
    int size;
    int* elements;
};

PriorityQueue Initialize(int capacity)
{
    PriorityQueue Q=(PriorityQueue)malloc(sizeof(struct HeapRecord));
    Q->capacity=capacity;
    Q->size=0;
    Q->elements=(int*)malloc(sizeof(int)*(capacity+1));
    Q->elements[0]=-60000;
    return Q;
}

void Insert(PriorityQueue H,int x)
{
    int i;
    for(i=++H->size;x<H->elements[i/2];i/=2)
        H->elements[i]=H->elements[i/2];
    H->elements[i]=x;
}

void Insert2(PriorityQueue H,int x)
{
    H->elements[++H->size]=x;
}

void PercDown(PriorityQueue H,int p)
{
    int parent,child;
    int x;

    x=H->elements[p];
    for(parent=p;parent*2<=H->size;parent=child)
    {
        child=parent*2;
        if(child!=H->size && H->elements[child]>H->elements[child+1])
            child++;
        if(x<=H->elements[child])
            break;
        else
            H->elements[parent]=H->elements[child];
    }
    H->elements[parent]=x;
}

void BuildHeap(PriorityQueue H)
{
    for(int i=H->size/2;i>0;i--)
        PercDown(H,i);
}

int main()
{
    int n;
    scanf("%d",&n);

    PriorityQueue H1=Initialize(255);
    PriorityQueue H2=Initialize(255);
    
    int x;

    for(int i=0;i<n;i++)
    {
        scanf("%d,",&x);

        Insert(H1,x);
        Insert2(H2,x);
    }
    BuildHeap(H2);

    printf("%d",H1->elements[1]);
    for(int i=2;i<=H1->size;i++)
        printf(",%d",H1->elements[i]);
    
    printf("\n");

    printf("%d",H2->elements[1]);
    for(int i=2;i<=H2->size;i++)
        printf(",%d",H2->elements[i]);


    return 0;
}



