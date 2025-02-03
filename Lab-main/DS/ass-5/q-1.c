#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void intial_elements(struct node **head,int n){
    *head = (struct node *)malloc(sizeof(struct node));
    struct node *newnode = NULL,*temp=NULL;
    if(*head == NULL){
        printf("Memory is not allocated properly\n");
        return;
    }
    for(int i=0;i<n;i++){
        newnode = (struct node *)malloc(sizeof(struct node));
        if(i==0){
            *head = newnode;
            printf("Enter your data 1: ");
            scanf("%d",&(newnode)->data);
            newnode->next=NULL;
            temp=newnode;
        }
        else{
            printf("Enter your data %d: ",i+1);
            scanf("%d",&(newnode)->data);
            newnode->next=NULL;
            temp->next=newnode;
            temp=newnode;
        }
    }
    temp->next=*head;
}
void printlist(struct node **head){
    struct node *temp = *head;
    printf("%d-> ",temp->data);
    temp = temp->next;
    while(temp!=*head){
        printf("%d-> ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int size(struct node **head){
    struct node *temp = *head;
    int count = 1;
    temp = temp->next;
    while(temp!=*head){
        count++;
        temp = temp->next;
    }
    return count;
}
void insert(struct node **head,int n){
    printf("Enter the position you want to insert the data: ");
    int x;
    scanf("%d",&x);
    struct node *temp , *newnode;
    newnode = (struct node * )malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory is not allocated properly");
        return;
    }
    if(x==1){
        printf("Enter your data: ");
        scanf("%d",&(newnode)->data);
        newnode->next = *head;
        *head = newnode;
        temp = *head;
        temp = temp->next;
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
        newnode->next = *head;
        temp->next = newnode;
    }
    else{
        for(int i=0;i<x-2;i++){
            temp = temp->next;
        }
        printf("Enter the data: ");
        scanf("%d",&(newnode)->data);
        newnode->next=temp->next;
        temp->next=newnode;
        temp = newnode->next;
    }
}
int main(){
    // printf("DFGFHFDHFDGHDDGHF");
    int n ;
    printf("Enter the number of the elements you want to enter in the linked list: ");
    scanf("%d",&n);
    struct node *head = NULL;
    intial_elements(&head,n);
    printf("Inital data: ");
    printlist(&head);
    n = size(&head);
    insert(&head , n);
    printf("%d",n);
    return 0;
}