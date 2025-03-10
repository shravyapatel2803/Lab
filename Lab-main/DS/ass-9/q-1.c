#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    int priority;
    struct node *next;
    struct node *previous;
};

void insert(struct node **front, struct node **rear) {
    int y = 1;
    while (y) {
        struct node *newnode, *temp1;
        printf("Enter 1 to continue and 0 to exit: ");
        scanf("%d", &y);

        if (y == 0) {
            break;
        }

        temp1 = *rear;
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data & priority of element: ");
        scanf("%d", &(newnode->data));
        scanf("%d",&(newnode->priority));

        if (*front == NULL) {
            *front = newnode;
            *rear = newnode;
            newnode->next = NULL;
            newnode->previous = NULL;
        } else {
            if (newnode->priority >= temp1->priority) {
                temp1->next = newnode;
                newnode->next = NULL;
                newnode->previous = temp1;
                *rear = newnode; // Update the rear pointer
            } else {
                struct node *temp2 = *front;
                while (temp2 != NULL) {
                    if (newnode->priority < temp2->priority) {
                        if (temp2->previous != NULL) {
                            temp2->previous->next = newnode;
                        } else {
                            *front = newnode; // Update the front pointer if new node is at the beginning
                        }
                        newnode->previous = temp2->previous;
                        temp2->previous = newnode;
                        newnode->next = temp2;
                        break;
                    }
                    temp2 = temp2->next;
                }
            }
        }
    }
}

void printQueue(struct node *front) {
    struct node *temp = front;
    while (temp != NULL) {
        printf("%d (Priority: %d) -> ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *front = NULL, *rear = NULL;
    insert(&front, &rear);
    // struct node* newnode1 = (struct node*)malloc(sizeof(struct node));
    // newnode1->priority = 1;
    // newnode1->data = 12;
    // struct node* newnode2 = (struct node*)malloc(sizeof(struct node));
    // newnode2->priority = 2;
    // newnode1->data = 12;
    // front = newnode1;
    // rear = newnode2;
    // newnode1->next = newnode2;
    // newnode2->next = NULL;
    // newnode1->previous = NULL;
    // newnode2->previous = newnode1;
    printQueue(front);
    return 0;
}
