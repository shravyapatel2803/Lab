#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
struct node {
    int data;
    // int priority;
    struct node *next;
    // struct node *previous;
};

// int main(int argc, char const *argv[])
// {
//     /* code */
//     int z = 1;
//     while (z)
//     {

//         /* code */
//     }
    
//     return 0;
// }
void insert_At_Front(struct node *front){
    struct node *newnode ,*temp = front;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: -");
    scanf("%d",&(newnode)->data);
    newnode->next = temp;
    front = newnode;

}
void insert_At_Rear(struct node *rear){
    struct node *newnode = (struct node*)malloc(sizeof(struct node)),*temp = rear;
    printf("Enter data: -");
    scanf("%d",&(newnode)->data);
    temp->next = newnode;
    newnode->next = NULL;
    rear = newnode;

}
void insert_Inital_Elements(struct node * front,struct node *rear){
    struct node *newnode,*temp;
    int condition = 1;
    int size = 0;
    while (condition==1&&size<SIZE)
    {
        printf("Enter 1 to continue and 0 to exit:- ");
        int  x ;
        scanf("%d",&x);
        if(x==1){
            newnode = (struct node*)malloc(sizeof(struct node));
            if(front == NULL&& rear == NULL){
                printf("Enter the data:- ");
                scanf("%d",&(newnode)->data);
                newnode->next=NULL;
                front = newnode;
                rear = newnode;
                temp = newnode;
            }
            else{
                
                printf("Enter the data:- ");
                scanf("%d",&(newnode)->data);
                temp->next = newnode;
                newnode ->next = NULL;
                rear = newnode;
                temp = newnode;
            }
            size++;
        }
        else if(x==0)
            condition = 0;
        else 
            printf("Enter valid choice");
        /* code */
    }
    
}
int main(int argc, char const *argv[])
{
    struct node *front = NULL,*rear = NULL;
    insert_Inital_Elements(front,rear);
    // int condition = 1;
    // while (condition)
    // {
    //     printf("Enter 1 to insert at front\nEnter 2 to insert at end")
    // }
    

    return 0;
}

