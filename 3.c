/*Push and Pop a value in the stack and then display it */
#include <stdio.h>
#include <stdlib.h>
#define MAX 3
int arr[MAX],top=-1;

void push(int arr[],int val);
int pop(int arr[]);
void Display(int arr[]);

int main(){
    int val,option;
    do{
        printf("\n MAIN MENU ");
        printf("\n 1. PUSH ");
        printf("\n 2. POP ");
        printf("\n 3. DISPLAY ");
        printf("\n 4. EXIT ");

        printf("\nEnter the option : ");
        scanf("%d",&option);

        switch(option){
            case 1:
            printf("Enter the value : ");
            scanf("%d",&val);
            push(arr,val);
            break;

            case 2:
            val = arr[top];
            if(top != -1){
                printf("The Value Removed is : %d ",val);
            }
            break;

            case 3:
            Display(arr);
            break;
        }
    }while(option !=4);
    return 0;
}
void push(int arr[],int val){
    if(top == MAX-1){
        printf("\nStack Overflow");
    }
    else{
        top ++;
        arr[top] = val;
    }
}
int pop(int arr[]){
    int val;
    if(top == -1){
        printf("Stack Underflow");
    }
    else{
        val = arr[top];
        top--;
    }

}
void Display(int arr[]){
    if(top == -1){
        printf("Stack is empty ");
    }
    else{
        for(int i =0;i<=top;i++){
            printf("%d ",arr[i]);
        }
    }
}