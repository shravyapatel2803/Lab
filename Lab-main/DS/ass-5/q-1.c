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
}
int size(struct node **head){
    struct node *temp = *head;
    int count = 1;
    temp = temp->next;
    while(temp!=*head){
        count++;
        temp = temp->next;
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
    return 0;
}