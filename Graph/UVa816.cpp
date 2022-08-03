#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

const char *dirs = "NESW";
const char *turns = "FLR";
const int MAXN = 10;
int d[MAXN][MAXN][4];

struct Node
{
    int r;
    int c;
    int dir;
    Node(int r = 0, int c = 0, int dir = 0) : r(r), c(c), dir(dir) {}
};

int dir_id(char c)
{
    return strchr(dirs, c) - dirs;
}

int turns_id(char c)
{
    return strchr(turns, c) - turns;
}

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

Node walk(const Node &n, int turn)
{
    int dir = n.dir;
    if (turn == 1)
        dir = (dir + 3) % 4;
    if (turn == 2)
        dir = (dir + 1) % 4;
    return Node(n.r + dr[dir], n.c + dc[dir], dir);
}

bool has_edge[MAXN][MAXN][4][4];
string maze;
Node startNode;
Node finalNode;
Node situation;

Node p[MAXN][MAXN][4];

bool input()
{
    memset(has_edge, 0, sizeof(has_edge));
    char tmp;
    cin >> maze;

    if (maze == "END")
        return false;
    cin >> startNode.r >> startNode.c >> tmp >> finalNode.r >> finalNode.c;

    situation.dir = tmp;
    situation.r = startNode.r + dr[situation.dir];
    situation.c = startNode.c + dc[situation.dir];

    int tmpr, tmpc;
    string tmps;
    while (cin >> tmpr, tmpr)
    {
        cin >> tmpc;
        while (cin >> tmps, tmps != "*")
        {
            for (int i = 1; i < tmps.length(); i++)
            {
                has_edge[tmpr][tmpc][dir_id(tmps[0])][turns_id(tmps[i])] = true;
            }
        }
    }
    return true;
}

bool isInside(int r, int c)
{
    return r > 0 && c > 0 && r < MAXN && c < MAXN;
}

void printAns(Node &n)
{
    vector<Node> vecNodes;
    while(true)
    {
        vecNodes.push_back(n);

        if(!d[n.r][n.c][n.dir]) break;
        Node tmp = n;
        n = p[n.r][n.c][n.dir];
        p[tmp.r][tmp.c][tmp.dir] = Node();
    }

    vecNodes.push_back(startNode);
    const int eachLineNums=10;
    int cnt=0;

    for(auto it=vecNodes.end()-1;it>=vecNodes.begin();it--)
    {
        if(cnt%eachLineNums) cout<<" ";
        else cout<<"  ";
        
        cout << "(" << (*it).r << "," << (*it).c << ")";
        if(!(++cnt % eachLineNums)) cout << endl;
    }
    
    if(vecNodes.size() % 10) cout << endl;
    return;
}


void solve()
{
    cout << maze <<endl;
    queue<Node> q;
    memset(d, -1, sizeof(d));
    Node n =situation;
    d[n.r][n.c][n.dir]=0;
    q.push(n);

    while (!q.empty())
    {
        n=q.front();q.pop();
        if(n.r==finalNode.r&&n.c==finalNode.c)
        {
            printAns(n);
            return;
        }
        for(int i=0;i<3;i++)
        {
            if(has_edge[n.r][n.c][n.dir][i])
            {
                Node v=walk(n,i);
                if(isInside(v.r,v.c)&&d[v.r][v.c][v.dir]==-1)
                {
                    d[v.r][v.c][v.dir]=d[n.r][n.c][n.dir]+1;
                    p[v.r][v.c][v.dir]=n;
                    q.push(v);
                }
            }
        }
    }
    
    cout << "  No Solution Possible" << endl;
    return;
}


int main()
{
    while (input())
        solve();
    
    return 0;
}

