//纯模拟

#include <stdio.h>
#include <stack>

using namespace std;

const int maxn = 1000 + 5;

int target[maxn];

int main()
{
    int n;
    while (scanf("%d", &n) && n != 0)
    {

        for (int i = 1; i <= n; i++)
            scanf("%d", &target[i]);

        
        int A = 1, B = 1;
        stack<int> s;
        int ok = 1;


        while (B<=n)
        {
            if (A == target[B])
            {
                A++;
                B++;
            }
            else if (!s.empty() && s.top() == target[B])
            {
                B++;
                s.pop();
            }
            else if (A <=n )
            {
                s.push(A);
                A++;
            }
            else
            {
                ok = 0;
                break;
            }
        }
        if (ok) //三目运算符
            printf("Yes\n");
        else
            printf("No\n");
    
    
    }

    return 0;
}
