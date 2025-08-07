/*linked STACK*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct stack{
    int data;
    struct stack *next;
};
struct stack *top = NULL;
struct stack *PUSH(struct  stack *,int);
struct stack *POP(struct stack *);
struct stack *DISPLAY(struct stack *);
struct stack *PEEK(struct stack *);

int main(){
    int val,option;
    do{
        printf("\n MAIN MENU ");
        printf("\n 1. PUSH");
        printf("\n 2. PULL ");
        printf("\n 3. PEEK");
        printf("\n 4. Display");
        printf("\n 5. EXIT ");
        printf("\nEnter the option : ");
        scanf("%d",&option);

        switch(option){
            case 1:
            printf("Enter the element to be pushed in the stack : ");
            scanf("%d",&val);
            top = push(top,val);
            break;

            case 2:
            top = pop(top);
            break;

            case 3:
            val = peek(top);
            if()



        }while(option!=5);
        return 0

    }
}


