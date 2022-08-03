#include<cstdio>
#include<cstring>

int const maxn=20;
int tree[1<<maxn];// 2^maxn-1

int main()
{
    int n,D,I;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&D,&I);    
        memset(tree,0,sizeof(tree));
        for(int j=1;j<=I;j++)
        {
            int pos=1;//编号为j的小球所在的初始位置
            while (pos<(1<<D))//编号为j的小球还在树内
            {
                tree[pos]=!tree[pos];//改变开关
                pos= tree[pos]? pos*2:pos*2+1;//小球目前的位置
            }
            if(j==I)//第I个小球
                printf("%d\n",pos/2);    
        }
    }
    return 0;
}