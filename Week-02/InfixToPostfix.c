/*
Write
a program to convert a given valid parenthesized
infix arithmetic expression to a postfix expression. The expression consists of
single-character operands and the binary operators + (plus), - (minus), *
(multiply), and / (divide). 
*/
#include <stdio.h>

char stack[50];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int priority(char x)
{
    if(x == '+' || x == '-')
        return 1;

    if(x == '*' || x == '/')
        return 2;

    return 0;
}

int main()
{
    char infix[50], postfix[50];
    int i, j = 0;
    char x;

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    for(i = 0; infix[i] != '\0'; i++)
    {
        if((infix[i] >= 'A' && infix[i] <= 'Z') ||
           (infix[i] >= 'a' && infix[i] <= 'z'))
        {
            postfix[j++] = infix[i];
        }

        else if(infix[i] == '(')
        {
            push(infix[i]);
        }

        else if(infix[i] == ')')
        {
            if(top == -1)
            {
                printf("Invalid expression! Enter a valid parenthesized infix expression.");
                return 0;
            }

            while(top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }

            if(top == -1)
            {
                printf("Invalid expression");
                return 0;
            }

            pop();
        }

        else if(infix[i] == '+' || infix[i] == '-' ||
                infix[i] == '*' || infix[i] == '/')
        {
            while(top != -1 && stack[top] != '(' &&
                  priority(stack[top]) >= priority(infix[i]))
            {
                postfix[j++] = pop();
            }

            push(infix[i]);
        }

        else
        {
            printf("Invalid expression");
            return 0;
        }
    }

    /* Check for unmatched opening brackets */
    while(top != -1)
    {
        if(stack[top] == '(')
        {
            printf("Invalid expression");
            return 0;
        }

        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s", postfix);

    return 0;
}
