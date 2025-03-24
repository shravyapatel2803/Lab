#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    if (q->front == -1) q->front = 0;
    q->data[++q->rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue(Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->data[q->front++];
    if (q->front > q->rear) q->front = q->rear = -1;
    printf("Dequeued: %d\n", value);
    return value;
}

int peek(Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->data[q->front];
}

int isFull(Queue* q) {
    return q->rear == MAX_SIZE - 1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

int main() {
    Queue* q = createQueue();
    char c;
    int value;

    while (1) {
        printf("\nChoose an option:\n");
        printf("e - Enqueue\n");
        printf("d - Dequeue\n");
        printf("p - Peek front element\n");
        printf("x - Exit\n");
        printf("Enter choice: ");
        
        scanf(" %c", &c); // Added space before %c to handle newline issue

        if (c == 'e') {
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(q, value);
        } else if (c == 'd') {
            dequeue(q);
        } else if (c == 'p') {
            printf("Front element: %d\n", peek(q));
        } else if (c == 'x') {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid input! Try again.\n");
        }
    }

    free(q);
    return 0;
}
