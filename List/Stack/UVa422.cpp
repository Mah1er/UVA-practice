// 简单的表达式解析可用栈完成
// 遇到字母时入栈，遇到)则出栈并计算，计算结构入栈
// 由于该题保证输入合法， (无需入栈


#include<cstdio>
#include<stack>
#include<iostream>
#include<string>

using namespace std;

struct Matrix
{
    int a,b;
    Matrix(int a=0,int b=0):a(a),b(b){}
}m[26];

stack<Matrix>s;

int main()
{   
    int n;
    cin>>n;

    while (n--)// 处理输入
    {
        string name;
        cin>>name;
        int k=name[0]-'A';
        cin>>m[k].a>>m[k].b;
    }

    string expr;
    int sum;
    bool error;
    while (cin>>expr)// 注意该写法
    {
        sum=0;
        error=false;

        int len=expr.length();
        for(int i=0;i<len&&(!error);i++)
        {
            if(isalpha(expr[i])) 
                s.push(m[expr[i]-'A']);// 字母表示index
            else if(expr[i]==')')
            {
                Matrix mb=s.top();s.pop();
                Matrix ma=s.top();s.pop();

                if(ma.b==mb.a)
                {
                    Matrix nm=Matrix(ma.a,mb.b);
                    s.push(nm);
                    sum+=ma.a*ma.b*mb.b;
                }
                else
                {
                    error=true;
                }
            }
        }
        if(error)
            printf("error\n");
        else
            printf("%d\n",sum);
    }
    
    return 0;
}





