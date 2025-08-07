/*PUSH POP PEEK in a Stack*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int arr[MAX],top=-1;

void push(int arr[],int val);
int pop(int arr[]);
int peek(int arr[]);
void Display(int arr[]);

int main(){
    int val,option;
    do{
        printf("\n MAIN MENU ");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");
        printf("\nEnter the option : ");
        scanf("%d",&option);

        switch(option){
            case 1:
            printf("Enter the value : ");
            scanf("%d",&val);
            push(arr,val);
            break;

            case 2: 
            val = pop(arr);
            if(val != -1){
                printf("The Element removed from the list is : %d ",val);
            }
            break;

            case 3:
            val = peek(arr);
            if(val != -1){
                printf("The Element displayed at the top of the stack : %d ",val);
            }
            break;

            case 4:
            printf("Elements in the stack are : ");
            Display(arr);
            break;
        }
    }while(option != 5);
    return 0;
}
void push(int arr[],int val){
    if(top == MAX-1){
        printf("Stack Overflow");
    }
    else{
        top++;
        arr[top] = val;
    }
}
int pop(int arr[]){
    int val;
    if(top == -1 ){
        printf("Stack Underflow");
        return -1;
    }
    else{
        val = arr[top];
        top--;
        return val;
    }
}
void Display(int arr[]){
    if(top == -1){
        printf("Stack is Empty");
    }
    else{
        for(int i=0;i<=top;i++){
            printf("%d ",arr[i]);
        }
    }
}
int peek(int arr[]){
    int val;
    if(top == -1){
        printf("Stack is Empty");
        return -1;
    }
    else{
        val = arr[top];
        return val;
    }
}

