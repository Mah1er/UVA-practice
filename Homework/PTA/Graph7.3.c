#include<stdio.h>
#include<stdlib.h>
#define inf 1e9

struct table;
typedef struct table *Table;

struct table
{
    int x;
    int known;
    int dist;
    int lastVex;
};

void dijkstra(Table T[],int a[8][8])
{
    for(int cnt=1;cnt<=7;cnt++)
    {
        int min=inf;
        int v;

        for(int i=1;i<=7;i++)
        {
            if(T[i]->known==0)
            {
                if(min>T[i]->dist)
                {
                    min=T[i]->dist;
                    v=i;
                }
            }
        }

        T[v]->known=1;

        for(int w=1;w<=7;w++)
        {
            if(a[v][w]!=inf && T[w]->known==0)
            {
                if(a[v][w]+T[v]->dist<T[w]->dist)
                {
                    T[w]->dist=a[v][w]+T[v]->dist;
                    T[w]->lastVex=v;
                }
            }
        }
    }
}

int main()
{
    int a[8][8];
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
            a[i][j]=inf;
    }

    a[1][2] = 2;
    a[1][4] = 1;
    a[2][4] = 3;
    a[2][5] = 10;
    a[3][1] = 4;
    a[3][6] = 5;
    a[4][3] = 2;
    a[4][5] = 2;
    a[4][6] = 8;
    a[4][7] = 4;
    a[5][7] = 6;
    a[7][6] = 1;

    Table T[8];
    for(int i=0;i<8;i++)
    {
        T[i]=(Table)malloc(sizeof(struct table));
        T[i]->dist=inf;
        T[i]->known=0;
        T[i]->lastVex=0;
    }

    int v,w;
    scanf("%d,%d",&v,&w);

    T[v]->dist=0;
    dijkstra(T,a);


    int flag=0;
    if(T[w]->lastVex!=0)
    {
        flag=1;
        int array[8];

        int i=0;
        array[i]=w;
        while (T[array[i]]->lastVex!=0)
        {
            array[i+1]=T[array[i]]->lastVex;
            i++;
        }
        
        for(;i>=0;i--)
            printf("%d,",array[i]);
    }
    if(flag==0)
        printf("-1");

    return 0;
}


