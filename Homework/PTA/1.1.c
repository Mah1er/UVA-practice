// 1. 栈的链表实现
// 2. 可以模拟栈


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct StackRecord* Stack;


struct StackRecord
{
    char value;
    Stack next;
};

void push(char c,Stack head)
{
    Stack s=head->next;

    Stack tmp=(Stack)malloc(sizeof(struct StackRecord));

    head->next=tmp;
    tmp->value=c;
    tmp->next=s;
}

void pop(Stack head)
{
    Stack tmp=head->next;
    head->next=tmp->next;
    free(tmp);    
}



int isempty(Stack head)
{
    return head->next==NULL;
}


int main()
{
    int boo1,boo2,boo3;
    boo1=boo2=boo3=1;

    Stack s1,s2,s3;
    s1=(Stack)malloc(sizeof(struct StackRecord));
    s2=(Stack)malloc(sizeof(struct StackRecord));
    s3=(Stack)malloc(sizeof(struct StackRecord));
    
    s1->next=NULL;
    s2->next=NULL;
    s3->next=NULL;



    char str[51];

    fgets(str,51,stdin);

    char tmp;
    for(int i=0;i<strlen(str);i++)
    {
        tmp=str[i];
        if(tmp=='(')
            push(tmp,s1);
        else if(tmp==')')
        {
            if(isempty(s1))
                boo1=0;
            else
                pop(s1);
        }

        if(tmp=='[')
            push(tmp,s2);
        else if(tmp==']')
        {
            if(isempty(s2))
                boo2=0;
            else
                pop(s2);
        }

        if(tmp=='{')
            push(tmp,s3);
        else if(tmp=='}')
        {
            if(isempty(s3))
                boo3=0;
            else
                pop(s3);
        }


    }
    
    if(!isempty(s1))
        boo1=0;

    if(!isempty(s2))
        boo2=0;

    if(!isempty(s3))
        boo3=0;

    if(boo1 && boo2 &&boo3)
        printf("0\n");

    else
    {
        if(!boo1) printf("1,");
        if(!boo2) printf("2,");
        if(!boo3) printf("3,");
        printf("\n");
    }

    return 0;
}



