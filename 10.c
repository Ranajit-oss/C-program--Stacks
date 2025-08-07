/*Infix to postfix*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define Max 100

char stack[Max];
int top=-1;

char infix[100],postfix[100],prefix[100];

void push(char stack[],char val);
char pop(char stack[]);
void infix_to_postfix_prefix(char source[],char target[],int for_prefix);
int get_Priority(char op);
void reverse(char arr[]);

int main(){
    printf("Enter the Expression : ");
    fgets(infix,sizeof(infix),stdin);
    printf("The Expression is : ");
    puts(infix);
    infix[strcspn(infix,"\n")] = '\0';

    top = -1;
    strcpy(postfix,"");
    infix_to_postfix_prefix(infix,postfix,0);
    printf("The Postfix Expression is : ");
    puts(postfix);

    reverse(infix);
    top = -1;
    strcpy(prefix,"");
    infix_to_postfix_prefix(infix,prefix,1);
    reverse(prefix);
    printf("The Prefix Expression is : ");
    puts(prefix);

    return 0;
}

void reverse(char arr[]){
    int i=0,j;
    int len = strlen(arr);
    for(i=0,j=len-1;i<j;i++,j--){
        char temp_char = arr[i];
        arr[i] = arr[j] ;
        arr[j] = temp_char;
    }
    for(i=0;i<len;i++){
        if(arr[i] == '('){
            arr[i] = ')';
        }
        else if(arr[i] == ')'){
            arr[i] = '(';
        }
    }

}
void infix_to_postfix_prefix(char source[],char target[],int for_prefix){
    int i=0,j=0;
    while(source[i] != '\0'){
        if(source[i] == '('){
            push(stack,source[i]);
            i++;
        }
        else if(isalnum(source[i])){
            target[j++] = source[i];
            i++;
        }
        else if(source[i] == ')'){
            while((top != -1) && (stack[top] != '(')){
                target[j++] = pop(stack);
            }
            if(top == -1){
                printf("Error in Stack");
                exit(1);
            }
            pop(stack);
            i++;
        }
        else if(source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] =='/' ||source[i] =='%'){

            while((top != -1) && (stack[top] != '(') && (((for_prefix == 0) && (get_Priority(stack[top]) >= get_Priority(source[i]))) 
            || ((for_prefix == 1) && (get_Priority(stack[top]) > get_Priority(source[i])))))
            {
                target[j++] = pop(stack);
            }
            push(stack,source[i]);
            i++;
        }
        else{
            printf("Invalid Expression : %c",source[i]);
            exit(1);
        }
    }
    while(top != -1  && stack[top] != '('){
        target[j++] = pop(stack) ;
    }
    target[j] = '\0';
}

void push(char stack[],char val){
    if(top == Max-1){
        printf("Stack Overflow ");
        exit(1);
    }
    else{
        top++;
        stack[top] = val;
    }
}
char pop(char stack[]){
    if(top == -1){
        printf("Stack Underflow");
        exit(1);
    }
    else{
        char val = stack[top];
        top--;
        return val;
    }
}
int get_Priority(char op){
    if(op == '*' || op == '/' || op =='%'){
        return 2;
    }
    else if(op == '+' || op =='-'){
        return 1;
    }
    else{
        return 0;
    }
}

