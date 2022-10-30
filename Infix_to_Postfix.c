/*A program to convert an infix expression to postfix expression and evaluate it*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>

int top=-1;

int isFull(int n)
{
    if(top==n-1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void push(int n, char *stack, char value)
{
    if(isFull(n))
        puts("!!! Stack Overflow !!!");
    else
        stack[++top]=value;
}

char pop(char *stack)
{
    if(isEmpty())
    {
        puts("!!! Stack Underflow !!!");
        return CHAR_MIN;
    }
    else
        return stack[top--];
}

int precedence(char symbol)
{
	if(symbol=='^' || symbol=='$')
		return 3;
	else if(symbol=='*' || symbol=='/')
		return 2;
	else if(symbol=='+' || symbol=='-')
		return 1;
	else
		return 0;
}

void postfix(char *infix_exp, char *postfix_exp)
{
    char temp1[strlen(infix_exp)+1];
    int i;
    int count=0;
    char curr_item;
	push(strlen(infix_exp),temp1,'(');
	strcat(infix_exp,")");
    for(i=0;i<=strlen(infix_exp)-1;i++)
    {
        curr_item=infix_exp[i];
        if((curr_item>='0' && curr_item<='9') || (curr_item>='A' && curr_item<='Z') || (curr_item>='a' && curr_item<='z'))
        {
            postfix_exp[count]=curr_item;
            count++;
        }
        else if(curr_item=='(')
            push(strlen(infix_exp),temp1,curr_item);
        else if(curr_item=='+' || curr_item=='-' || curr_item=='*' || curr_item=='/' || curr_item=='^' || curr_item=='$')
        {
            while((curr_item=='+' || curr_item=='-' || curr_item=='*' || curr_item=='/' || curr_item=='^' || curr_item=='$') && precedence(temp1[top])>=precedence(curr_item))
            {
                postfix_exp[count]=pop(temp1);
                count++;
            }
            push(strlen(infix_exp),temp1,curr_item);
        }
        else if(curr_item==')')
        {
            while(temp1[top]!='(')
            {
                postfix_exp[count]=pop(temp1);
                count++;
            }
            pop(temp1);
        }
        else if(curr_item==' ')
            continue;
    }
    top=-1;
}

int evaluate_postfix(char *postfix_exp)
{
    char temp2[strlen(postfix_exp)];
    int i,operator1,operator2;
    char curr_item;
    for(i=0;i<=strlen(postfix_exp)-1;i++)
    {
        curr_item=postfix_exp[i];
        if((curr_item>='A' && curr_item<='Z') || (curr_item>='a' && curr_item<='z'))
            return INT_MAX;
        else if(curr_item>='0' && curr_item<='9')
            push(strlen(postfix_exp),temp2,curr_item-'0');
        else if(curr_item=='+' || curr_item=='-' || curr_item=='*' || curr_item=='/' || curr_item=='^' || curr_item=='$')
        {
            operator2=pop(temp2);
            operator1=pop(temp2);
            switch(curr_item)
            {
                case '+': push(strlen(postfix_exp),temp2,operator1+operator2); 
                          break;
                case '-': push(strlen(postfix_exp),temp2,operator1-operator2); 
                          break;
                case '*': push(strlen(postfix_exp),temp2,operator1*operator2);
                          break;
                case '/': push(strlen(postfix_exp),temp2,operator1/operator2);
                          break;
                case '^': push(strlen(postfix_exp),temp2,pow(operator1,operator2));
                          break;
                case '$': push(strlen(postfix_exp),temp2,pow(operator1,operator2));
                          break;
                default: break;
            }
        }
    }
    
    return temp2[top];
}

int main()
{
    char infix_exp[100];
    char postfix_exp[100];
    printf("Enter an infix operation (Don't use alphabets and integers together as an operand): ");
    gets(infix_exp);

    postfix(infix_exp,postfix_exp);

	printf("\nPostfix Expression: ");
    puts(postfix_exp);
    if(evaluate_postfix(postfix_exp)!=INT_MAX)
        printf("Result of the operation: %d\n",evaluate_postfix(postfix_exp));
    else
        puts("\nThe infix operation input is using variables as operands. Evaluation isn't possible...");

    return 0;
}