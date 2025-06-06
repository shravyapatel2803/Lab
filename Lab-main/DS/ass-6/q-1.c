#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int data;
    struct node *pre;
} node;
void intial_elements(node **head)
{
    int y = 1;
    *head = NULL;
    node *temp = NULL, *newnode;
    int i = 0;
    while (y)
    {
        printf("Enter 1 to enter new data else enter 2 to exit\n");
        int condition;
        scanf("%d", &condition);
        switch (condition)
        {
        case 1:
            newnode = (node *)malloc(sizeof(node));
            printf("Enter the data: ");
            scanf("%d", &(newnode)->data);
            newnode->pre = temp;
            *head = newnode;
            temp = newnode;
            break;
        case 2:
            y = 0;
            break;
        default:
            printf("Try again\n");
        }
    }
}
void print_stack(node **head)
{
    node *temp = *head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->pre;
    }
    printf("NULL\n");
}
void insert(node **head)
{
    node *temp = *head;
    node *newnode = NULL;
    int y = 1;
    while (y)
    {
        printf("Enter 1 to insert new data or else enter 2: ");
        int condition;
        scanf("%d", &condition);
        switch (condition)
        {
        case 1:
            newnode = (node *)malloc(sizeof(node));
            printf("Enter the data: ");
            scanf("%d", &(newnode)->data);
            newnode->pre = temp;
            *head = newnode;
            temp = newnode;
            break;
        case 2:
            y = 0;
            break;
        default:
            printf("Try again\n");
            break;
        }
    }
}
void pop(node **head)
{
    if (*head == NULL)  // Stack underflow check
    {
        printf("Stack is empty\n");
        return;
    }

    int y = 1;
    while (y)
    {
        printf("Enter 1 to pop the element, else enter 2 to exit: ");
        int condition;
        scanf("%d", &condition);

        switch (condition)
        {
        case 1:
            {
                node *temp = *head;
                printf("Popped: %d\n", temp->data);
                *head = temp->pre;  // Move head to next node
                free(temp);         // Free the old head
                if (*head == NULL)
                {
                    printf("Stack is now empty.\n");
                    return;
                }
            }
            break;
        case 2:
            y = 0;
            break;
        default:
            printf("Try again\n");
            break;
        }
    }
}

int main()
{
    node *head = NULL;
    intial_elements(&head);
    print_stack(&head);
    printf("Insert: \n");
    insert(&head);
    print_stack(&head);
    pop(&head);
}