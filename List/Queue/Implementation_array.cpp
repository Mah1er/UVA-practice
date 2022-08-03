#define ElementType int

struct QueueRecord;
typedef struct QueueRecord *Queue;


int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void MakeEmpty(Queue Q);

void Enqueue(ElementType X,Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType* Array;
};

int IsEmpty(Queue Q)
{
    return Q->Size==0;
}

void MakeEmpty(Queue Q)
{
    Q->Size=0;
    Q->Rear=0;
    Q->Front=0;
}

int IsFull(Queue Q)
{
    return Q->Capacity==Q->Size;
}

static int Succ(int SuccIndex,Queue Q)
{
    if(++SuccIndex==Q->Capacity)
        SuccIndex=0;
    return SuccIndex;
}


void Enqueue(ElementType X,Queue Q)
{
    if(IsFull(Q))
        throw "Full queue";
    else
    {
        Q->Size++;
        Q->Rear=Succ(Q->Rear,Q);
        Q->Array[Q->Rear]=X;
    }
}

