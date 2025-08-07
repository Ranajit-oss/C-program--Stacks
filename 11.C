#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define Max 100

char stack[Max],infix[100],postfix[100],prefix[100];
int top = -1;

void push(char stack[],char val);
char pop(char stack[]);
