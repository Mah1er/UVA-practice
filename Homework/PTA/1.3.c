#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct listnode* list;

struct listnode
{
    int value;
    list next;
};


int main()
{
    char str [101];
    fgets(str,101,stdin);
    
    int ans1[101];
    int ans2[101];

    int count=0;
    int flag=1;

    for(int i=0;i<strlen(str)-1;i+=2)
    {
        ans1[i/2]=str[i]-'0';
    }

    for(int i=strlen(str)-3;i>=0;i-=2)
    {
        ans2[count++]=str[i]-'0';
    }

    for(int i=0;i<count;i++)
    {
        if(ans1[i]!=ans2[i])
        {
            flag=0;
            break;
        }
    }
    
    if(flag) printf("Yes\n");
    else printf("No\n");

    return 0;

}



