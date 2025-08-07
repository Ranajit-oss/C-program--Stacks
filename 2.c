/*Push a value in the stack and display it */
#include <stdio.h>
#include <stdlib.h>
#define MAX 3
int arr[MAX],top = -1;

void push(int arr[],int val);
void Display(int arr[]);

int main(){
    int val,option;

    do{
        printf("\n MAIN MENU ");
        printf("\n 1. PUSH ");
        printf("\n 2. DISPLAY ");
        printf("\n 3. EXIT ");

        printf("\nEnter the option : ");
        scanf("%d",&option);

        switch(option){
            case 1:
                printf("Enter the value : ");
                scanf("%d",&val);
                push(arr,val);
                break;
            case 2:
                Display(arr);
                break;
        }
    }while(option !=3);
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
void Display(int arr[]){
    for(int i = 0 ; i<=top;i++){
        printf("%d ",arr[i]);
    }
}