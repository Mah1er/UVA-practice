#define ELementType int

typedef struct TreeNode *PtrToNode;

struct TreeNode
{
    ELementType Element;
    PtrToNode FirstChild;
    PtrToNode NextSibling;
};

// 所有树都可以被转换成二叉树，利用如上的形式
