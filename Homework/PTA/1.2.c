// int priotity处理优先级
// 不是数字的情况分情况讨论

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct StackRecord* Stack;

struct StackRecord
{
    char value;
    double dig;
    Stack next;
};


void pop(Stack head)
{
    if(head->next!=NULL)
    {    
        Stack tmp = head->next;
        head->next=tmp->next;
        free(tmp);
    }
}


char top(Stack head)
{
    if(head->next!=NULL)
        return head->next->value;    
}

double top1(Stack head)
{
    if(head->next!=NULL)
        return head->next->dig;    
}

void push(Stack head,char c)
{
    Stack tmp =(Stack)malloc(sizeof(struct StackRecord));
    tmp->value=c;
    tmp->next=head->next;
    head->next=tmp;
}

void push1(Stack head,double c)
{
    Stack tmp =(Stack)malloc(sizeof(struct StackRecord));
    tmp->dig=c;
    tmp->next=head->next;
    head->next=tmp;
}

int priority(char op)
{
    if( op=='*' || op=='/') return 2;
    if( op=='+' || op=='-') return 1;
    if( op=='(') return 0;
}

int isempty(Stack head)
{
    return head->next==NULL;
}


int main()
{
    char str[110];
    char ans[110];

    char tmp;
    int count=0;

    fgets(str,110,stdin);

    Stack s=(Stack)malloc(sizeof(struct StackRecord));
    s->next=NULL;

    Stack s1=(Stack)malloc(sizeof(struct StackRecord));
    s1->next=NULL;

    //strlen(str)-1 处理'\n'
    for(int i=0;i<strlen(str)-1;i++)
    {
        tmp=str[i];

        if(tmp>='0'&& tmp<='9')
            ans[count++]=tmp;
//            printf("%c ",tmp);
        else // 非数字 分情况讨论
        {
            if(isempty(s))
                push(s,tmp);
            else if(tmp=='(')
                push(s,tmp);
            else if(tmp==')')
            {
                while (top(s)!='(')
                {
                    ans[count++]=top(s);                
                    //printf("%c ",top(s));//
                    pop(s);
                }
                pop(s);//弹出左括号
            }

            else
            {
                while (priority(top(s))>=priority(tmp))
                {
                    ans[count++]=top(s);

                    //printf("%c ",top(s));//
                    pop(s); 

                    if(isempty(s)) break;
                }
                push(s,tmp);
            }
        }
    }

    while (!isempty(s))
    {
        ans[count++]=top(s);
        //printf("%c ",top(s));//
        pop(s);
    }

    for (int i = 0; i < count; i++)
    {
        if(ans[i]>='0'&&ans[i]<='9')
            push1(s1,ans[i]-'0');
        
        else if(ans[i]=='+')
        {
            double a= top1(s1); pop(s1);
            double b= top1(s1); pop(s1);
            push1(s1,a+b);
        }
        else if(ans[i]=='*')
        {
            double a= top1(s1); pop(s1);
            double b= top1(s1); pop(s1);
            push1(s1,a*b);
        }
        else if(ans[i]=='-')
        {
            double a= top1(s1); pop(s1);
            double b= top1(s1); pop(s1);
            push1(s1,b-a);
        }
        else if(ans[i]=='/')
        {
            double a= top1(s1); pop(s1);
            double b= top1(s1); pop(s1);
            push1(s1,b/a);
        }
    }
    
    double answer=top1(s1);

    printf("%.2f\n",answer);

    for(int i=0;i<count;i++)
        printf("%c ",ans[i]);
    
    printf("\n");



    return 0;

}


