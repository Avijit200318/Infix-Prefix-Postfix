#include<stdio.h>
#include<ctype.h>
#include<string.h>

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
        case ')':return 0;
        case '(':return 1;
        case '+':
        case '-':return 2;
        case '*':
        case '/':
        case '%':return 3;
        case '^':return 4;
    }
}

char reverse(char infix[])
{
    char a;
    int lb=0,ub=strlen(infix)-1;
    while(lb<ub)
    {
        a=infix[lb];
        infix[lb]=infix[ub];
        infix[ub]=a;
        lb++;
        ub--;
    }
    return infix[size];
}

int main()
{
    char infix[size],prefix[size];
    char ch;
    int k=0,i=0;
    printf("enter the infix expression:");
    scanf("%s",infix);
    printf("the infix expression of %s ",infix);
    reverse(infix);    
    push(')');
    while((ch=infix[i++])!='\0')
    {
        if(ch==')')
        {
            push(ch);
        }
        else if(isalnum(ch))
        {
            prefix[k++]=ch;
        }
        else if(ch=='(')
        {
            while(stack[top]!=')')
            {
                prefix[k++]=pop();
            }
            pop();
        }
        else
        {
            while((prece(stack[top])>prece(ch)) && prece(stack[top])!=prece(ch))
            {
                prefix[k++]=pop();
            }
            push(ch);
        }
    }
    while(stack[top]!=')')
    {
        prefix[k++]=pop();
    }
    prefix[k]='\0';
    reverse(prefix);
    printf("equivalent prefix is: %s",prefix);
    return 0;
}
