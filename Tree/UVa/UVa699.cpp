#include<iostream>
#include<cstring>

using namespace std;
const int maxn= 100005;
int sum[maxn];
//数组的每一个index代表水平位置的一个节点

void build(int p)
{
    int v;
    cin>>v;
    if(v==-1) return ;
    sum[p]+=v;
    build(p-1);
    build(p+1);
}

bool init()
{
    int v;
    cin>>v;
    if(v==-1) return false;
    memset(sum,0,sizeof(sum));
    int pos=maxn/2;
    sum[pos]+=v;
    build(pos-1);
    build(pos+1);
    return true;
}


int main()
{   
    int kase=0;
    while ((init()))
    {
        int p=0;
        while ((sum[p]==0))
        {
            p++;
        }
        
        cout<<"Case "<<++kase<<":\n"<<sum[p++];//避免行末多余括号

        while (sum[p]!=0)
        {
            cout<<" "<<sum[p++];
        }
        cout<<"\n\n";


    }
    


    return 0;
}




