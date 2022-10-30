/*A program to convert an infix expression to prefix expression and evaluate it*/

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

void push(int n,char *stack, char value)
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
            while((curr_item=='+' || curr_item=='-' || curr_item=='*' || curr_item=='/' || curr_item=='^' || curr_item=='$') && precedence(temp1[top])>precedence(curr_item))
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

int evaluate_prefix(char *prefix_exp)
{
    char temp2[strlen(prefix_exp)];
    int i,operator1,operator2;
    char curr_item;
    for(i=strlen(prefix_exp)-1;i>=0;i++)
    {
        curr_item=prefix_exp[i];
        if((curr_item>='A' && curr_item<='Z') || (curr_item>='a' && curr_item<='z'))
            return INT_MAX;
        else if(curr_item>='0' && curr_item<='9')
            push(strlen(prefix_exp),temp2,curr_item-'0');
        else if(curr_item=='+' || curr_item=='-' || curr_item=='*' || curr_item=='/' || curr_item=='^' || curr_item=='$')
        {
            operator1=pop(temp2);
            operator2=pop(temp2);
            switch(curr_item)
            {
                case '+': push(strlen(prefix_exp),temp2,operator1+operator2); 
                          break;
                case '-': push(strlen(prefix_exp),temp2,operator1-operator2); 
                          break;
                case '*': push(strlen(prefix_exp),temp2,operator1*operator2);
                          break;
                case '/': push(strlen(prefix_exp),temp2,operator1/operator2);
                          break;
                case '^': push(strlen(prefix_exp),temp2,pow(operator1,operator2));
                          break;
                case '$': push(strlen(prefix_exp),temp2,pow(operator1,operator2));
                          break;
                default: break;
            }
        }
    }
    
    return temp2[top];
}

void prefix(char *infix_exp, char *prefix_exp)
{
    int i;
    strrev(infix_exp);
    for(i=0;i<=strlen(infix_exp)-1;i++)
    {
        if(infix_exp[i]==')')
            infix_exp[i]='(';
        else if(infix_exp[i]=='(')
            infix_exp[i]=')';
    }
    postfix(infix_exp,prefix_exp);
    strrev(prefix_exp);
}

int main()
{
    char infix_exp[100];
    char postfix_exp[100];
    char prefix_exp[100];
    printf("Enter an infix operation (Don't use alphabets and integers together as an operand): ");
    gets(infix_exp);

    prefix(infix_exp,prefix_exp);

	printf("\nPrefix Expression: ");
    puts(prefix_exp);
    /*if(evaluate_prefix(prefix_exp)!=INT_MAX)
        printf("Result of the operation: %d\n",evaluate_prefix(prefix_exp));
    else
        puts("\nThe infix operation input is using variables as operands. Evaluation isn't possible...");  /*5+(4-3)*6/2+1   gcc Infix_to_Prefix.c*/

    return 0;
}
