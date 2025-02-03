#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *previous;
    struct node *next;
};
void intial_elements ( struct node **head , int n ){
    struct node *temp,*newnode;
    *head = (struct node *)malloc(sizeof(struct node));
    if(*head == NULL){
        printf("Memory not allocated\n");
        return;
    }
    printf("Enter the data for node 1: ");
    scanf("%d",&(*head)->data);
    (*head)->previous = NULL;
    (*head)->next = NULL;
    temp = *head;
    for (int i=1;i<n;i++){
        newnode = (struct node *)malloc(sizeof(struct node));
        if(newnode == NULL){
            printf("Memory not allocated\n");
        }
        printf("Enter the data for node %d: ",i+1);
        scanf("%d",&newnode->data);
        newnode->previous = temp;
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
    }
}
void printlist(struct node **head){
    struct node *temp = *head;
    while(temp != NULL){
        printf("%d-> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void insert (struct node **head , int x , int n){
    struct node *temp , *newnode;
    newnode = (struct node * )malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory is not allocated properly");
        return;
    }
    if(x==1){
        printf("Enter your data: ");
        scanf("%d",&(newnode)->data);
        newnode->previous = NULL;
        newnode->next = *head;
        *head = newnode;
        return;
    }
    else if(x==n){
        temp = *head;
        newnode = (struct node * )malloc(sizeof(struct node));
        for(int i=1;i<=n-1;i++){
            temp = temp->next;
        }
        printf("Enter the data: ");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        newnode->previous=temp;
        temp->next = newnode;
    }
    else{
        for(int i=0;i<x-2;i++){\
            temp = temp->next;
        }
        printf("Enter the data: ");
        scanf("%d",&(newnode)->data);
        newnode->next=temp->next;
        newnode->previous=temp;
        temp->next=newnode;
        temp = newnode->next;
        temp->previous = newnode;
    }
}
void delete(struct node **head , int x , int n){
    struct node * temp=*head,newnode;
    
}
int main(void){
    struct node *head;
    int n;
    printf("Enter the number of elements you want to enter\n");
    scanf("%d",&n);
    intial_elements(&head,n);
    printlist(&head);
    int x;
    printf("Enter your position where you want to enter your data\n");
    scanf("%d",&x);
    insert(&head,x,n);
    printlist(&head);
    return 0;
}