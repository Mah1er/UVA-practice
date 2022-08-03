#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<algorithm>

using namespace std;

const int maxn = 10000 + 10;

int inorder[maxn],postorder[maxn]; // 存输入

// 用于建立左右子树
// eg: 若根为root, 则它的左儿子为 lch[root],右儿子为[root]
int lch[maxn],rch[maxn];
int n;

bool read_list(int *arr) // 学习读入
{
    string line;
    if(!getline(cin,line)) return false;

    stringstream ss (line);
    int x;
    n = 0;
    while(ss>>x)
        arr[n++]=x;
    return n > 0;
}

//把inorder[L1...R1]和postorder[L2...R2]建成树

int build(int L1,int R1,int L2,int R2)
{
    if(L1>R1) 
        return 0; // 空树
    
    int root=postorder[R2]; // 根 or 子根
    int p = L1;
    
    while(inorder[p]!=root)
        p++;

    int cnt=p-L1; // 左子树节点数
    lch[root]=build(L1,p-1,L2,L2+cnt-1);
    rch[root]=build(p+1,R1,L2+cnt,R2-1);
    return root;
}


int best_sum, best;
void DFS(int u,int sum)
{
    sum+=u;
    if(lch[u]==0&&rch[u]==0)
    {
        if(best_sum>sum||(best_sum==sum&&best>u))
        {
            best_sum=sum;
            best=u;
        }
    }
    if(lch[u])
        DFS(lch[u],sum);
    if(rch[u])
        DFS(rch[u],sum);
}
 
int main()
{
    while (read_list(inorder))
    {        
        read_list(postorder);
        
        memset(lch,0,sizeof(lch));
        memset(rch,0,sizeof(lch));
        int root=build(0,n-1,0,n-1);
        
        best_sum=100000;
        DFS(root,0);
        printf("%d\n",best);
    }
    

    return 0;
}

