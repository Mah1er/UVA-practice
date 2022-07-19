#include<cstdio>

int main()
{
    int n,D,I;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&D,&I);
        int pos=1;//初始位置    
        for(int j=0;j<D-1;j++)
        {
            if(I%2)//奇数
            {
                pos*=2;
                I=(I+1)/2;
            }
            else
            {
                pos=pos*2+1;
                I/=2;
            }
        }
        printf("%d\n",pos);
    }
    return 0;
} 