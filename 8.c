/*Infix to Postfix */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define Max 100

char stack[Max];
int top = -1;

void push(char stack[], char val);
char pop(char stack[]);
void infix_to_postfix(char source[], char target[]);
int getPriority(char);

int main() {
    char infix[100], postfix[100];
    printf("Enter any infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0'; // remove newline
    strcpy(postfix, "");

    infix_to_postfix(infix, postfix);
    printf("The Corresponding Postfix Expression is: ");
    puts(postfix);

    return 0;
}

void infix_to_postfix(char source[], char target[]) {
    int i = 0, j = 0;
    char temp;

    while (source[i] != '\0') {
        if (source[i] == '(') {
            push(stack, source[i]);
            i++;
        }

        else if (isalnum(source[i])) {  // handles both letters and digits
            target[j++] = source[i++];
        }

        else if (source[i] == '/' || source[i] == '*' || source[i] == '%' || source[i] == '+' || source[i] == '-') {
            while ((top != -1) && (stack[top] != '(') && (getPriority(stack[top]) >= getPriority(source[i]))) {
                target[j++] = pop(stack);
            }
            push(stack, source[i]);
            i++;
        }

        else if (source[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                target[j++] = pop(stack);
            }
            if (top == -1) {
                printf("\nIncorrect Expression: Unmatched Parentheses\n");
                exit(1);
            }
            pop(stack); // remove '('
            i++;
        }

        else {
            printf("Incorrect character in expression: %c\n", source[i]);
            exit(1);
        }
    }

    while (top != -1 && stack[top] != '(') {
        target[j++] = pop(stack);
    }
    target[j] = '\0';
}

void push(char stack[], char val) {
    if (top == Max - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = val;
    }
}

char pop(char stack[]) {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int getPriority(char op) {
    if (op == '/' || op == '*' || op == '%') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    } else {
        return 0; // for non-operators
    }
}
