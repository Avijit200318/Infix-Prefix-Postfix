#include<stdio.h>
#include<ctype.h>

#define size 20

char stack[size];
int top=-1;

void push(char ch)
{
    stack[++top]=ch;
}

char pop()
{
    return stack[top--];
}

int prece(char ch)
{
    switch(ch)
    {
        case '(':return 0;
        case ')':return 1;
        case '+':
        case '-':return 2;
        case '*':
        case '/':
        case '%':return 3;
        case '^':return 4;
    }
}

int main()
{
    char infix[size],postfix[size];
    char ch;
    int k=0,i=0;
    printf("enter the infix expression:");
    scanf("%s",infix);
    printf("the infix expression of %s ",infix);
    push('(');
    while((ch=infix[i++])!='\0')
    {
        if(ch=='(')
        {
            push(ch);
        }
        else if(isalnum(ch))
        {
            postfix[k++]=ch;
        }
        else if(ch==')')
        {
            while(stack[top]!='(')
            {
                postfix[k++]=pop();
            }
            pop();
        }
        else
        {
            while(prece(stack[top])>=prece(ch))
            {
                postfix[k++]=pop();
            }
            push(ch);
        }
    }
    while(stack[top]!='(')
    {
        postfix[k++]=pop();
    }
    postfix[k]='\0';
    printf("equivalent postfix is %s",postfix);
    return 0;
}
