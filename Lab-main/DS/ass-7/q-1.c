#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100


typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void push(Stack *s, char value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->data[++s->top] = value;
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->data[s->top--];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}


void infixToPostfix(char *infix, char *postfix) {
    Stack opStack;
    opStack.top = -1;
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&opStack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&opStack) && opStack.data[opStack.top] != '(') {
                postfix[j++] = pop(&opStack);
            }
            pop(&opStack); 
        } else { 
            while (!isEmpty(&opStack) && precedence(infix[i]) <= precedence(opStack.data[opStack.top])) {
                postfix[j++] = pop(&opStack);
            }
            push(&opStack, infix[i]);
        }
    }

    while (!isEmpty(&opStack)) {
        postfix[j++] = pop(&opStack);
    }

    postfix[j] = '\0'; 
}






int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}