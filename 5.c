/*Multiple Stack*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX],topA=-1,topB=MAX;

void pushA(int stack[],int val){
    if(topA == topB-1){
        printf("Stack Overflow");
    }
    else{
        topA++;
        stack[topA] = val;
    }
}

int popA(int stack[]){
    int val;
    if(topA == -1){
        printf("Stack Underflow");
    }
    else{
        val = stack[topA];
        topA--;
        return val;
    }
}

void DisplayA(int stack[]){
    if(topA == -1){
        printf("Stack Is Empty ");
    }
    else{
        for(int i=0;i<=topA;i++){
            printf("%d ",stack[i]);
        }
    }
}
void pushB(int stack[],int val){
    if(topB-1 == topA){
        printf("Stack Overflow");
    }
    else{
        topB--;
        stack[topB] = val;
    }
}

int popB(int stack[]){
    int val;
    if(topB == MAX){
        printf("Stack Underflow");
    }
    else{
        val = stack[topB];
        topB++;
        return val;
    }
}

void DisplayB(int stack[]){
    if(topB == MAX){
        printf("Stack Is Empty ");
    }
    else{
        for(int i=topB;i<MAX;i++){
            printf("%d ",stack[i]);
        }
    }
}

int main(int argv,char *argc){
    int val,option;
    
    do{
        printf("\n  MAIN MENU  ");
        printf("\n 1. PUSH STACK A ");
        printf("\n 2. POP STACK A ");
        printf("\n 3. DISPLAY STACK A ");
        printf("\n 4. PUSH STACK B ");
        printf("\n 5. POP STACK B ");
        printf("\n 6. DISPLAY STACK B ");
        printf("\n 7. EXIT ");
        printf("\n Enter your option : ");
        scanf("%d",&option);
            
        switch(option){
            case 1: 
            printf("Enter the value to be pushed in stack A : ");
            scanf("%d",&val);
            pushA(stack,val);
            break;

            case 2:
            val = popA(stack);
            if(topA != -1){
                printf("The value removed from stack A : %d ",val);
            }
            break;
            
            case 3:
            printf("The Stack A is : ");
            DisplayA(stack);
            break;
                        
            case 4: 
            printf("Enter the value to be pushed in stack B : ");
            scanf("%d",&val);
            pushB(stack,val);
            break;

            case 5:
            val = popB(stack);
            if(topB != -1){
                printf("The value removed from stack B : %d ",val);
            }
            break;

            case 6:
            printf("The Stack B is : ");
            DisplayB(stack);
            break;
        }
    }while(option !=7);
}