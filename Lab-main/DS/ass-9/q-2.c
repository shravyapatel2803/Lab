#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5  // Define the maximum size of the deque

typedef struct {
    int arr[SIZE];
    int front, rear;
} Deque;

// Function to initialize the deque
void initialize(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

// Function to check if the deque is empty
int isEmpty(Deque *dq) {
    return (dq->front == -1);
}

// Function to check if the deque is full
int isFull(Deque *dq) {
    return ((dq->rear + 1) % SIZE == dq->front);
}

// Function to insert an element at the front
void insertFront(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full! Cannot insert at front.\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + SIZE) % SIZE;
    }
    dq->arr[dq->front] = value;
    printf("Inserted %d at front.\n", value);
}

// Function to insert an element at the rear
void insertRear(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full! Cannot insert at rear.\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % SIZE;
    }
    dq->arr[dq->rear] = value;
    printf("Inserted %d at rear.\n", value);
}

// Function to delete an element from the front
void deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty! Cannot delete from front.\n");
        return;
    }
    printf("Deleted %d from front.\n", dq->arr[dq->front]);
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;  // Reset if deque becomes empty
    } else {
        dq->front = (dq->front + 1) % SIZE;
    }
}

// Function to delete an element from the rear
void deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty! Cannot delete from rear.\n");
        return;
    }
    printf("Deleted %d from rear.\n", dq->arr[dq->rear]);
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;  // Reset if deque becomes empty
    } else {
        dq->rear = (dq->rear - 1 + SIZE) % SIZE;
    }
}

// Function to display the deque
void display(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements: ");
    int i = dq->front;
    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function to test the deque implementation
int main() {
    Deque dq;
    initialize(&dq);
    
    while (true) {
        printf("\nEnter your choice:\n");
        printf("1 - Insert at front\n");
        printf("2 - Insert at rear\n");
        printf("3 - Delete from front\n");
        printf("4 - Delete from rear\n");
        printf("5 - Check if the queue is full\n");
        printf("6 - Check if the queue is empty\n");
        printf("7 - Display the deque\n");
        printf("0 - Exit\n");
        printf("Choice: ");

        int choice, value;
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Exiting program...\n");
                return 0;

            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(&dq, value);
                break;

            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(&dq, value);
                break;

            case 3:
                deleteFront(&dq);
                break;

            case 4:
                deleteRear(&dq);
                break;

            case 5:
                if (isFull(&dq))
                    printf("Deque is full.\n");
                else
                    printf("Deque is not full.\n");
                break;

            case 6:
                if (isEmpty(&dq))
                    printf("Deque is empty.\n");
                else
                    printf("Deque is not empty.\n");
                break;

            case 7:
                display(&dq);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
