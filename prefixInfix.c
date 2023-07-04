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

char reverse(char arr[size])
{
        char a;
        int lb=0,ub=strlen(arr)-1;
        while(lb<ub)
        {
                a=arr[lb];
                arr[lb]=arr[ub];
                arr[ub]=a;
                lb++;
                ub--;
        }
        return arr[size];
}

int main()
{
        char prefix[size];
        char ch;
        int i=0;
        char op1[size],op2[size];
        printf("enter the prefix expression:");
        scanf("%s",prefix);
        printf("the prefix expression is: %s ",prefix);
        reverse(prefix);
        while((ch=prefix[i++])!='\0')
        {
                if(isalnum(ch))
                {
                        char buffer[]={ch,'\0'};
                        push(buffer);
                }
                else
                {
                        char buffer[]={ch,'\0'};
                        char left[size]={')','\0'};
                        char right[size]={'(','\0'};
                        pop(op2);
                        pop(op1);
                        strcat(left,op1);
                        strcat(left,buffer);
                        strcat(left,op2);
                        strcat(left,right);
                        push(left);
                }
        }
        reverse(stack[top]);
        printf("equvalent infix exprssion is %s",stack[top]);
}
