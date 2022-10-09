#include<stdio.h>
#include<math.h>

int is_prime(int n)
{
    if(n%2==0 && n!=2)
        return 0;
    if(n==1)
        return 1;
    for(int i=2;i<sqrt(n);i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d",&n);
    if(is_prime(n))
        printf("%d is a prime number\n",n);
    else
        printf("%d is not a prime number\n",n);
    return 0;
}

