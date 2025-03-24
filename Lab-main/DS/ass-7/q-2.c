#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

Stack *createStack(int capacity) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (!s) {
        perror("Error: Memory allocation failed");
        exit(1);
    }
    s->data = (int *)malloc(capacity * sizeof(int));
    if (!s->data) {
        perror("Error: Memory allocation failed");
        exit(1);
    }
    s->top = -1;
    s->capacity = capacity;
    return s;
}

void push(Stack *s, int value) {
    if (s->top == s->capacity - 1) {
        s->capacity *= 2;
        s->data = (int *)realloc(s->data, s->capacity * sizeof(int));
        if (!s->data) {
            perror("Error: Memory reallocation failed");
            exit(1);
        }
    }
    s->data[++s->top] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Error: Not enough operands in the expression!\n");
        exit(1);
    }
    return s->data[s->top--];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void freeStack(Stack *s) {
    free(s->data);
    free(s);
}

int evaluatePostfix(char *postfix) {
    Stack *evalStack = createStack(MAX_SIZE);
    char *token = strtok(postfix, " ");

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) { 
            push(evalStack, atoi(token));
        } else {
            if (evalStack->top < 1) {
                printf("Error: Invalid postfix expression. Check the number of operands!\n");
                freeStack(evalStack);
                return 0;
            }
            int operand2 = pop(evalStack);
            int operand1 = pop(evalStack);
            int result = 0;
            switch (token[0]) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': 
                    if (operand2 == 0) {
                        printf("Error: Division by zero is not allowed!\n");
                        freeStack(evalStack);
                        return 0;
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Error: Unsupported operator '%c'\n", token[0]);
                    freeStack(evalStack);
                    return 0;
            }
            push(evalStack, result);
        }
        token = strtok(NULL, " ");
    }

    if (evalStack->top != 0) {
        printf("Error: Invalid postfix expression. Too many operands!\n");
        freeStack(evalStack);
        return 0;
    }

    int finalResult = pop(evalStack);
    freeStack(evalStack);
    return finalResult;
}

int main() {
    char postfix[MAX_SIZE];

    printf("Welcome to the Postfix Expression Evaluator!\n");
    printf("Enter your expression using space-separated numbers and operators (+, -, *, /).\n");
    printf("Type 'q' to exit.\n");

    while (1) {
        printf("\nEnter postfix expression: ");
        fgets(postfix, MAX_SIZE, stdin);

        if (postfix[0] == 'q' || postfix[0] == 'Q') {
            printf("Goodbye! Thanks for using the evaluator.\n");
            break;
        }

        postfix[strcspn(postfix, "\n")] = 0;

        if (strlen(postfix) == 0) {
            printf("Error: No input provided. Please enter a valid expression.\n");
            continue;
        }

        int result = evaluatePostfix(postfix);
        printf("final Result: %d\n", result);
    }

    return 0;
}
