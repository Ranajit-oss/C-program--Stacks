/*Parenthesis checker*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

char stack[MAX];
int top = -1;

void push(char stack[],char val);
char pop(char stack[]);

int main(){
    int i,flag=1;
    char val,arr[100],temp;

    printf("Enter the String : ");
    fgets(arr,sizeof(arr),stdin);
    arr[strcspn(arr,"\n")] = '\0';

    for(i=0;arr[i]!='\0';i++){

        if(arr[i] == '(' || arr[i] == '{' || arr[i] == '['){
            val = arr[i];
            push(stack,val);
        }
        if(arr[i] == ')' || arr[i] == '}' || arr[i] == ']'){
            if(top == -1){
                flag =0;
            }
            else{
                temp = pop(stack);
                if((arr[i] == ')') && (temp == '{' || temp == '['))
                flag = 0;
                if((arr[i] == '}') && (temp == '(' || temp == '['))
                flag =0;
                if((arr[i] == ']') && (temp == '(' || temp == '{'))
                flag = 0;
            }
        }
    }
    if(top >= 0){
        flag =0;
    }
    if(flag == 1){
        printf("Valid Expression");
    }
    else{
        printf("Not a Valid Expression");
    }
}

void push(char stack[],char val){
    if(top == MAX-1){
        printf("Stack Overflow ");
    }
    else{
        top++;
        stack[top] = val;
    }
}
char pop(char stack[]){
    int val;
    if(top == -1){
        printf("Stack Underflow ");
    }
    else{
        val = stack[top];
        top--;
        return val;
    }
}




