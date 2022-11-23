#include<stdio.h>
#include<string.h>
int Matrix[5][5];
int isodd[5];

int main()
{
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            Matrix[i][j]=0;
    
    char str[255];
    fgets(str,255,stdin);

    for(int i=0;i<5;i++)
        isodd[i]=0;

   for(int i=0;i<strlen(str)-2;i+=4)
    {
        int sub=str[i]-'0';
        int ob=str[i+2]-'0';    
        isodd[sub]++; 
        if(isodd[sub]%2==1)
        {
            Matrix[ob][sub]++;
        }
    }

    int n;
    scanf("%d",&n);
    int flag=1;

    for(int i=0;i<5;i++)
    {
       if(Matrix[n][i]==1)
       {
            printf("%d,",i);
            flag=0;
       }
    }
    if(flag==1) printf("-1");
    return 0;
}