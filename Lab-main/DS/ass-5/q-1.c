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
        temp = *head;
        for(int i=1;i<=n-1;i++){
            temp = temp->next;
        }
        newnode->next=*head;
        *head = newnode;
        temp->next=*head;

        return;
    }
    else if(x==n){
        temp = *head;
        // newnode = (struct node * )malloc(sizeof(struct node));
        for(int i=1;i<=n-1;i++){
            temp = temp->next;
        }
        printf("Enter the data: ");
        scanf("%d",&newnode->data);
        newnode->next = *head;
        temp->next = newnode;
    }
    else{
        temp = *head;
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
void delete(struct node **head,int n){
    printf("Enter the position you want to delete (total no elements are %d): ",n);
    struct node *temp,*temp1;
    int x;
    scanf("%d",&x);
    if (x == 1) {
        temp = *head;
        temp1 = *head;
        *head = temp->next;
        for (int i = 1; i <= n - 1; i++) {
            temp1 = temp1->next;
        }
        temp1->next = *head;
        free(temp);
        return;
    }
    else if(x == n){
        temp = *head;
        for (int i = 1; i <n; i++) {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = *head;
        free(temp);
        return;
    }
    else{
        temp = *head;
        struct node *next;
        for(int i = 1;i<x;i++){
            temp1 = temp;
            temp = temp->next;
        }
        next = temp->next;
        temp1->next=next;
        free(temp);
        return;
    }
}
int main(){
    // printf("DFGFHFDHFDGHDDGHF");
    int n ;
    printf("Enter the number of the elements you want to enter in the linked list: ");
    scanf("%d",&n);
    struct node *head = NULL,*undo = NULL;
    intial_elements(&head,n);
    printf("Inital data: ");
    printlist(&head);
    int y =1;
    while(y){
        printf("Enter 1 to insert\nEnter 2 to delete\nEnter 3 to undo\nEnter 4 to redo\nEnter 5 to exit\n");
        int condition;
        printf("Enter your condition: ");
        scanf("%d",&condition);
        switch (condition)
        {
        case 1:
            int n = size(&head);
            insert(&head,n);
            printlist(&head);
            // undo(&undo,&head)
            break;
        case 2 :
            int n = size(&head);
            delete(&head,n);
            printlist(&head);
            break;
        default:
            break;
        }
    }
    return 0;
}