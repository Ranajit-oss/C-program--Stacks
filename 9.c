/*Evaluation of a postfix expression*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define Max 100

float stack[Max];
int top = -1;

void push(float stack[],float val);
float pop(float stack[]);
float postfix_expression_value(char exp[]);

int main(char argc,char *argv){
    char exp[100];
    float value;
    printf("Enter the postfix expression : ");
    fgets(exp,sizeof(exp),stdin);

    exp[strcspn(exp,"\n")]='\0';
    value = postfix_expression_value(exp);
    printf("Value of the postfix expression : %.2f ",value);
}


float postfix_expression_value(char exp[]){
    int i;
    float op1,op2,value;
    while(exp[i] != '\0'){
        if(isdigit(exp[i])){
            push(stack,(float)(exp[i]-'0'));
        }
        else{
            op2 = pop(stack);
            op1 = pop(stack);
            switch(exp[i]){
                case '+':
                value = op1 + op2;
                break;

                case '-':
                value = op1 - op2;
                break;

                case '/':
                value = op1 / op2;
                break;

                case '*':
                value = op1 * op2;
                break;

                case '%':
                value = (int)op1 % (int)op2;
                break;
            }
            push(stack,value);
        }
        i++;
    }
    return (pop(stack));
}

void push(float stack[],float val){
    if(top == Max-1){
        printf("Stack Overflow ");
    }
    else{
        top++;
        stack[top] = val;
    }
}
float pop(float stack[]){
    if(top == -1){
        printf("Stack Underflow");
    }
    else{
        float val = stack[top];
        top--;
        return val;
    }
}
