#include <stdio.h>
char stack[100];
int top = -1;
char exp1[10];
int k = -1;
char s[] = "a+b/c*(d-e)";
char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
void push(char *c)
{
    top++;
    stack[top] = *c;
}
int precedence(char s)
{
    if (s == '*' || s == '/')
    {
        return 2;
    }
    else if (s=='+'||s=='-')
    {
        return 1;
    }
    // else if(s=='(')
    // {
    //     return 1;
    // }
    else 
    return 0;
}
void inToPo()
{
    char *c;
    for (int i = 0; s[i] != '\0'; i++)
    {
        c=&s[i];
        if (*c == '+' || *c == '%' || *c == '-' || *c == '*' || *c == '/')
        {
            while(precedence(stack[top]) >= precedence(s[i]) && top>-1){
                exp1[++k]=pop();
            }
            push(c);
        }
        else if (*c == '(')
        {
            push(c);
        }
        else if (*c == ')')
        {
            char x;
            while (( x = pop()) != '(')
            {   
                exp1[++k] = x;
            }
        }
        else
        {
            exp1[++k]=*c;
        }
    }
    while (top != -1)
    {
        exp1[++k] = pop();
    }
    printf("%s", exp1);
}
void main()
{
    printf("%s\n", s);
    inToPo();
}