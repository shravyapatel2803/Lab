#include <stdio.h>
#include <stdlib.h>

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
        scanf("%d %d", &(newnode->data), &(newnode->priority));
        newnode->next = NULL;
        newnode->previous = NULL;

        if (*front == NULL) {
            *front = newnode;
            *rear = newnode;
        } else {
            if (newnode->priority >= temp1->priority) {
                temp1->next = newnode;
                newnode->previous = temp1;
                *rear = newnode; // Update the rear pointer
            } else {
                struct node *temp2 = *front;
                while (temp2 != NULL) {
                    if (newnode->priority < temp2->priority) {
                        if (temp2->previous != NULL) {
                            temp2->previous->next = newnode;
                        } else {
                            *front = newnode; // Update front if new node is at the beginning
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

int size(struct node *front) {
    int i = 0;
    struct node *temp = front;
    while (temp != NULL) {
        i++;
        temp = temp->next;
    }
    return i;
}

void deleteAtPosition(struct node **front, struct node **rear, int pos) {
    if (*front == NULL) {
        printf("Queue is empty, cannot delete!\n");
        return;
    }

    int s = size(*front);
    if (pos < 1 || pos > s) {
        printf("Invalid position! Enter a value between 1 and %d.\n", s);
        return;
    }

    struct node *temp = *front;
    int count = 1;

    // Traverse to the node at position pos
    while (count < pos) {
        temp = temp->next;
        count++;
    }

    // If deleting the first node
    if (temp->previous == NULL) {
        *front = temp->next;
        if (*front != NULL) {
            (*front)->previous = NULL;
        } else {
            *rear = NULL; // If queue becomes empty
        }
    }
    // If deleting the last node
    else if (temp->next == NULL) {
        *rear = temp->previous;
        (*rear)->next = NULL;
    }
    // Deleting a middle node
    else {
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
    }

    free(temp);
    printf("Deleted element at position %d\n", pos);
}
void peeking(struct node **front,struct node **rear){
    struct node* temp1 = *front,*temp = *rear;;
    printf("MAX proirty element %d(priority: %d)\n",temp1->data,temp1->priority);
    
    printf("MIN proirty element %d(priority: %d)\n",temp->data,temp->priority);
}

int main() {
    struct node *front = NULL, *rear = NULL;
    int z = 1;
    while (z){
        printf("Enter 1 to 'insert'\nEnter 2 to 'delete'\nEnter 3 'to peeking'\nEnter 0 to 'exit'\n");
        int y ;
        int pos ;
        scanf("%d",&y);
        switch(y){
        case 1:
            insert(&front,&rear);
            printQueue(front);
            break;
        case 2:
            printf("Enter the position you want to delete\n");
            scanf("%d",&pos);
            deleteAtPosition(&front,&rear,pos);
            printQueue(front);
            peeking(&front,&rear);
            break;
        case 3:
        peeking(&front,&rear);
        break;
        case 0:
            z=0;
            break;
        default:
            printf("Invaild choice try again");

        }

    }
    return 0;
}
