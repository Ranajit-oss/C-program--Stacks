/*Write a program to reverse a List */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX],top = -1;

void push(int stack[],int val);
int pop(int stack[]);
void Display(int stack[],int n);

int main(){
    int arr[100],i,n,val,temp[100];
    printf("Enter the value of n : ");
    scanf("%d",&n);

    printf("Enter the elements : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(i =0;i<n;i++){
        val = arr[i];
        push(stack,val);
    }
    printf("The Elements in the stack are : ");
    Display(stack,n);

    for(i=0;i<n;i++){
        temp[i] = pop(stack);
    }

    printf("\nThe Reversed Array is : ");
    for(i=0;i<n;i++){
        printf("%d ",temp[i]);
    }
}
void push(int stack[],int val){
    if(top == MAX-1){
        printf("Stack Overflow");
    }
    else{
        top++;
        stack[top] = val;
    }
}
int pop(int stack[]){
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
void Display(int stack[],int n){
    if(top == -1){
        printf("Stack is Empty ");
    }
    else{
        for(int i=0;i<n;i++){
            printf("%d ",stack[i]);
        }
    }
}

