#include<string>
#include<cstdio>
#include<stack>
#include<iostream>

using namespace std;

struct Matrix
{
    int row;
    int col;
    Matrix(int row=0,int col=0):row(row),col(col){}
};

Matrix MatrixRecord[26];

int main()
{
    int n;
    cin>>n;

    string name;
    int index;

    for(int i=0;i<n;i++)
    {
        cin >> name;
        index=name[0]-'A';
        cin>>MatrixRecord[index].row>>MatrixRecord[index].col;
    }


    string expr;
    while (cin>>expr)
    {
        stack<Matrix> S;
        
        int len=expr.length();
        int ans=0;
        bool error=false;

        for(int i=0;i<len;i++)
        {
            if(expr[i]<='Z'&&expr[i]>='A')
            {
                int k=expr[i]-'A';
                S.push(MatrixRecord[k]);   
            }
            else if(expr[i]==')')
            {
                Matrix b=S.top();S.pop();
                Matrix a=S.top();S.pop();
                if(a.col!=b.row)
                {
                    error=true;
                    break;
                }
                else
                {
                    ans+=(a.row*a.col*b.col);
                    // Matrix c;
                    // c.row=a.row;
                    // c.col=b.col;
                    // S.push(c);
                    S.push(Matrix(a.row,b.col));
                }
            }
        }

        if(error)
            printf("error\n");
        else
        {
            printf("%d\n",ans);
        }
    
    }
    
    return 0;
}



