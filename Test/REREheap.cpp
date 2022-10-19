#include<stdio.h>
#include<stdlib.h>
#define MinData 1000000

typedef struct HeapRecord* PriorityQueue;

struct HeapRecord
{
    int size;
    int capacity;
    int *elements;
};

PriorityQueue Initialize(int capacity)
{
    PriorityQueue H;
    
    // if NULL
    H->capacity=capacity;
    H->size=0;
    H->elements=(int*)malloc(sizeof(int)*(capacity+1));
    H->elements[0]=MinData;
    return H;
}


void Insert(int x, PriorityQueue H)
{
    int i;
    
    // if full

    for(i=++H->size;x<H->elements[i/2];i/=2)
        H->elements[i]=H->elements[i/2];
    H->elements[i]=x;
}

void DeleteMin(PriorityQueue H)
{
    int i,child;

    int LastElement=H->elements[H->size--];

    for(i=1;i*2<=H->size;i=child)
    {
        child=i*2;
        
        if( child!=H->size && 
            H->elements[child]>H->elements[child+1])
            child++;

        if(LastElement>H->elements[child])
            H->elements[i]=H->elements[child];
        else
            break;
    }
    H->elements[i]=LastElement;
    return;

}





