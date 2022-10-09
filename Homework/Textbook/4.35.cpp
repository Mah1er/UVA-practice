#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

struct node
{
    int value;
    node* left;
    node* right;
};

void BFS(vector<int> &ans,node* root)
{
    queue<node*> reg;
    
    reg.push(root);
    node* tmp;

    while (!reg.empty())
    {
        tmp=reg.front(); reg.pop();

        if(tmp->left!=NULL) reg.push(tmp->left);
        if(tmp->right!=NULL) reg.push(tmp->right);
        ans.push_back(tmp->value);
    }
    return ;
}

