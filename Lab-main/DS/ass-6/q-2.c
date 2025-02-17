#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 5

int *stack, *undoStack, *redoStack;
int top = -1, undoTop = -1, redoTop = -1;
int capacity = INITIAL_CAPACITY, undoCapacity = INITIAL_CAPACITY, redoCapacity = INITIAL_CAPACITY;

void initStack() {
    stack = (int *)malloc(capacity * sizeof(int));
    undoStack = (int *)malloc(undoCapacity * sizeof(int));
    redoStack = (int *)malloc(redoCapacity * sizeof(int));
    if (!stack || !undoStack || !redoStack) {
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

void pushUndo(int data) {
    if (undoTop == undoCapacity - 1) {
        undoCapacity *= 2;
        undoStack = (int *)realloc(undoStack, undoCapacity * sizeof(int));
    }
    undoStack[++undoTop] = data;
}

void pushRedo(int data) {
    if (redoTop == redoCapacity - 1) {
        redoCapacity *= 2;
        redoStack = (int *)realloc(redoStack, redoCapacity * sizeof(int));
    }
    redoStack[++redoTop] = data;
}

void undo() {
    if (undoTop == -1) {
        printf("Nothing to undo!\n");
        return;
    }
    pushRedo(pop());
    undoTop--;
}

void redo() {
    if (redoTop == -1) {
        printf("Nothing to redo!\n");
        return;
    }
    push(redoStack[redoTop--]);
}

void freeStacks() {
    free(stack);
    free(undoStack);
    free(redoStack);
}

int main() {
    initStack();
    
    int choice, data;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Print Stack\n4. Undo\n5. Redo\n6. Exit\nEnter your choice: ");
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
                    pushUndo(data);
                    printf("Popped: %d\n", data);
                }
                break;
            case 3:
                printStack();
                break;
            case 4:
                undo();
                break;
            case 5:
                redo();
                break;
            case 6:
                freeStacks();
                return 0;
            default:
                printf("Invalid choice, try again!\n");
        }
    }
}
