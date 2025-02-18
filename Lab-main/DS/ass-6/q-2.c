#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 5

int *stack;
int top = -1;
int capacity = INITIAL_CAPACITY;

void initStack() {
    stack = (int *)malloc(capacity * sizeof(int));
    if (!stack) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

int isFull() {
    return top == capacity - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int data) {
    if (isFull()) {
        capacity *= 2;
        stack = (int *)realloc(stack, capacity * sizeof(int));
        if (!stack) {
            printf("Memory reallocation failed!\n");
            exit(1);
        }
    }
    stack[++top] = data;
}

int pop() {
    if (isEmpty()) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack[top--];
}

void printStack() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d -> ", stack[i]);
    }
    printf("NULL\n");
}

void freeStacks() {
    free(stack);
}

int main() {
    initStack();
    
    int choice, data;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Print Stack\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data = pop();
                if (data != -1) {
                    printf("Popped: %d\n", data);
                }
                break;
            case 3:
                printStack();
                break;
            case 4:
                freeStacks();
                return 0;
            default:
                printf("Invalid choice, try again!\n");
        }
    }
}
