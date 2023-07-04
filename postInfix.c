#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define size 20

char *stack[size];
int top=-1;

void push(char arr[size])
{
        stack[++top]=(char*)malloc(size*sizeof(char));
        strcpy (stack[top],arr);
}

void pop(char arr[size])
{
        strcpy(arr,stack[top--]);
}

int main()
{
        char postfix[size];
        char ch;
        int i=0;
        char op1[size],op2[size];
        printf("enter the postfix expression:");
        scanf("%s",postfix);
        printf("the postfix expression is: %s ",postfix);
        while((ch=postfix[i++])!='\0')
        {
                if(isalnum(ch))
                {
                        char buffer[]={ch,'\0'};
                        push(buffer);
                }
                else
                {
                        char buffer[]={ch,'\0'};
                        char left[size]={'(','\0'};
                        char right[size]={')','\0'};
                        pop(op2);
                        pop(op1);
                        strcat(left,op1);
                        strcat(left,buffer);
                        strcat(left,op2);
                        strcat(left,right);
                        push(left);
                }
        }
        printf("equvalent infix exprssion is %s",stack[top]);

}
