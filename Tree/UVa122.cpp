#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

struct Node
{
    bool have_value;
    int value;
    Node* left, *right;
    Node():have_value(false),left(NULL),right(NULL){};
};

bool failed;
Node* root;//根节点
const int maxn=100100;
char s[maxn];

Node * newnode()
{
    return new Node();
}


void addnode(int value,char *str)
{
    int n= strlen(str);
    Node * u= root;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='L')
        {
            if(u->left==NULL)
                u->left=newnode();
            u=u->left;
        }
        
        else if(str[i]=='R')
        {
            if(u->right==NULL)
                u->right=newnode();
            u=u->right;
        }
    }
    if(u->have_value) failed =true;
    u->value=value;
    u->have_value=true;
}

bool read_input() // 重点学习如何读入数据
{
    failed=false;
    root=newnode();
    for(;;)
    {
        if(scanf("%s",s)!=1) return false;
        if(!strcmp(s,"()")) break;
        int value;
        sscanf(&s[1],"%d",&value);
        addnode(value,strchr(s,',')+1);
    }
    return true;
}

bool BFS(vector <int> &ans)
{
    queue<Node*> q;
    ans.clear();
    q.push(root);
    while ((!q.empty()))
    {
        Node* tmp= q.front();
        q.pop();
        if(!tmp->have_value)
            return false;
        ans.push_back(tmp->value);
        if(tmp->left!=NULL)
            q.push(tmp->left);
        if(tmp->right!=NULL)
            q.push(tmp->right);            
    }
    return true;
}

int main()
{
    vector<int> ans;
    while (read_input())
    {
        if(failed||!BFS(ans))
            printf("not complete\n");
        else
        {
            int len=ans.size();
            for(int i=0;i<len-1;i++)
                printf("%d ",ans[i]);
            printf("%d\n",ans[len-1]);
        }
    }
    return 0;
}