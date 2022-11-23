#include<stdio.h>

int index(char c,char*str)
{
    int i;
    for(i=0;i<11;i++)
        if(str[i]==c) return i;
}

int inDegree(int j,int am[11][11])
{
    int inDgree=0;
    for(int i=0;i<11;i++)
        inDgree+=am[i][j];
    return inDgree;
}

int main()
{
    char name[11] = {
        'S',
        'A',
        'B',
        'C',
        'D',
        'E',
        'F',
        'G',
        'H',
        'I',
        'T',
    };
    int am[11][11];
    for(int i=0;i<11;i++)
        for(int j=0;j<11;j++)
            am[i][j]=0;

    am[0][1] = 1;
    am[0][4] = 1;
    am[0][7] = 1;
    am[1][2] = 1;
    am[1][5] = 1;
    am[2][3] = 1;
    am[3][10] = 1;
    am[4][1] = 1;
    am[4][5] = 1;
    am[5][3] = 1;
    am[5][6] = 1;
    am[5][9] = 1;
    am[6][3] = 1;
    am[6][10] = 1;
    am[7][4] = 1;
    am[7][5] = 1;
    am[7][8] = 1;
    am[8][5] = 1;
    am[8][9] = 1;
    am[9][10] = 1;
    am[9][6] = 1;

    char c1,c2;
    scanf("%c,%c",&c1,&c2);
    int x=index(c1,name);
    int y=index(c2,name);
    am[x][y]=0;

    int queue[11];
    int front=0;
    int rear=-1;
    int size=0;

    for(int i=0;i<11;i++)
    {
        int degree=inDegree(i,am);
        if(degree==0)
        {
            queue[++rear]=i;
            size++;
        }
    }

    while (size!=0)
    {
        int x=queue[front++];
        printf("%c,",name[x]);
        size--;
        for(int j=0;j<11;j++)
        {
            if(am[x][j]==1)
            {
                am[x][j]=0;
                if(inDegree(j,am)==0)
                {
                    queue[++rear]=j;
                    size++;
                }
            }
        }

    }
    return 0;
}


