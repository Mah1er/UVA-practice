// 把大小排序看成有向线段,则本题可看成一个拓扑排序

#include<iostream>
#include<vector>

using namespace std;


int n,m,t;
vector<vector<int>>G;//图
vector<int>book,topo;//标记,结果

bool dfs(int u)
{
	book[u] = -1; //-1标记为该节点正在访问中
	for (int i = 0; i < (int)G[u].size(); i++) //访问该节点指向了什么节点
	{
		if (book[G[u][i]] == -1) { return false; } //如果该节点中有节点也在访问中 说明是有向环
		//else if (book[G[u][i]] == 0 && !dfs(G[u][i])) { return false; } //原紫书代码 不好理解 换成下面的
		else if (book[G[u][i]] == 0) { dfs(G[u][i]); } //如果该节点指向的节点没被访问过 则对其进行递归访问
	}
	book[u] = 1; topo[--t] = u; //标记该节点访问完毕 并记录到结果中
	return true;
}

bool toposort()
{
    t=n;
    book=vector<int>(n+1);
    topo=vector<int>(n+1);
    for(int i=1;i<=n;i++)
    {
        if(book[i]==0)
        {
            if(!dfs(i))
               return false;
        }
    }
    return true;
}




int main()
{
    while (cin>>n>>m)
    {
        if(n==0 && m==0)
            break;
        G=vector<vector<int>>(n+1);
        for(int i=0;i<m;i++)
        {   
            int a,b;
            cin>>a>>b;
            G[a].push_back(b);
        }
        if(!toposort())
            cout<<-1;
        else
        {
            for (int i = 0; i < n; i++)
                cout<<topo[i]<<" ";
            cout<<endl;
        }
    }
    return 0; 
}



