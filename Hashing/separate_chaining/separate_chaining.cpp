#define ElementType const char*
#define MinTableSize 5
#include<cstdio>
#include<cstdlib>


struct ListNode;
typedef struct ListNode *Position;
typedef Position List;
struct HashTbl;
typedef struct HashTbl *HashTable;
typedef unsigned int Index;

struct ListNode
{
    ElementType Element;
    Position Next;
};

struct HashTbl
{
    int TableSize;
    List *TheLists;
};

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key,HashTable H);
void Insert(ElementType Key,HashTable H);
ElementType Retrieve(Position P);
int NextPrime(int i);
Index Hash(const char *Key,int TableSize);


HashTable InitializeTable(int TableSize)
{
    HashTable H;

    if(TableSize<MinTableSize)
    {
        throw "Table size too small";
        return NULL;
    }

    H=(HashTable)malloc(sizeof(struct HashTbl));
    if(H==NULL)
        throw"Out of space";
    
    H->TableSize=NextPrime(TableSize);

    H->TheLists=(List*)malloc(sizeof(List)* H->TableSize);
    if(H->TheLists==NULL)
        throw "Out of space";
    
    for(int i=0;H->TableSize;i++)
    {
        H->TheLists[i]=(List)malloc(sizeof(struct ListNode));
        if(H==NULL)
            throw "Out of space";
        else
            H->TheLists[i]->Next=NULL;
    }
    return H;
}


Position Find(ElementType key,HashTable H)
{
    Position P;
    List L;

    L=H->TheLists[Hash(key,H->TableSize)];
    P=L->Next;

    while(P!=NULL && P->Element!=key) // ATTENTION:if key is a string, use strcmp! 
    {
        P=P->Next;
    }
    return P; // if not found, return NULL
}

void Insert(ElementType key,HashTable H)
{
    Position Pos,NewCell;
    List L;

    Pos=Find(key,H);
    if(Pos==NULL)
    {
        NewCell=(Position)malloc(sizeof(struct ListNode));
        if(NewCell==NULL)
            throw "Out of space";
        else
        {
            L=H->TheLists[Hash(key,H->TableSize)];
            NewCell->Element=key;
            NewCell->Next=L->Next;
            L->Next=NewCell;
        }
    }
}


