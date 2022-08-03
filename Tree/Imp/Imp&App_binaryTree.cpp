#define ElementType char
#include<cstdio>
#include<stack>
using namespace std;

typedef struct TreeNode *PtrToNode;
typedef PtrToNode Tree;

struct TreeNode
{
    ElementType Element;
    Tree Left;
    Tree Right;
    TreeNode(char c):Element(c),Left(NULL),Right(NULL){};
};

const char* expr="ab+cde+**";
stack <Tree> s;

Tree newNode(char c)
{
    return new TreeNode(c);
}


void build()
{
    char*tmp=(char*)expr;
    while (*tmp)
    {
        if((*tmp)<='z'&&(*tmp)>='a')//push variable
        {
            Tree tmpTree=newNode(*tmp);
            s.push(tmpTree);
        }
        else if ((*tmp)=='+'||(*tmp)=='*')
        {
            Tree tmpTree=newNode(*tmp);
            Tree rightChild=s.top();s.pop();
            Tree leftChild=s.top();s.pop();
            tmpTree->Left=leftChild;
            tmpTree->Right=rightChild;
            s.push(tmpTree);
        }
        tmp++;
    }
}

int main()
{
    build();
    Tree exprTree=s.top();s.pop();

    return 0;
}
