#include<stdio.h>
#include<stdlib.h>
struct node{
    int expo;
    int coff;
    struct node *next;
};
void equation1_fun(struct node **equation1){
    int y = 1;
    int i = 1;
    struct node *temp,*newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the 1 term(first enter coff and then expo): ");
    scanf("%d %d",&(newnode)->coff,&(newnode)->expo);
    *equation1 = newnode;
    newnode->next=NULL;
    temp = newnode;
    while(y){
        printf("Enter 1 to add new term\nEnter 2 to exit\n");
        int condition;
        printf("Enter your choice: ");
        scanf("%d",&condition);
        switch (condition)
        {
        case 1:
            i = i+1;
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter the %d term(First enter coff and then expo): ",i);
            scanf("%d %d",&(newnode)->coff,&(newnode)->expo);
            temp->next=newnode;
            newnode->next=NULL;
            temp = newnode;
            break;
        case 2:
            y = 0;
            break;
        default:
        printf("Invalid input\n");
            break;
        }
    }
}
void equation2_fun(struct node **equation2){
    int y = 1;
    int i = 1;
    struct node *temp,*newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the 1 term(first enter coff and then expo): ");
    scanf("%d %d",&(newnode)->coff,&(newnode)->expo);
    *equation2 = newnode;
    newnode->next=NULL;
    temp = newnode;
    while(y){
        printf("Enter 1 to add new term\nEnter 2 to exit\n");
        int condition;
        printf("Enter your choice: ");
        scanf("%d",&condition);
        switch (condition)
        {
        case 1:
            i = i+1;
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter the %d term(First enter coff and then expo): ",i);
            scanf("%d %d",&(newnode)->coff,&(newnode)->expo);
            temp->next=newnode;
            newnode->next=NULL;
            temp = newnode;
            break;
        case 2:
            y = 0;
            break;
        default:
        printf("Invalid input\n");
            break;
        }
    }
}
void printlist(struct node **head){
    struct node *temp = *head;
    while(temp!=NULL){
        printf("(%d,%d)->",temp->coff,temp->expo);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main(){
    struct node *equation1=NULL,*equation2=NULL,*final_equation=NULL;
    printf("Enter the data of the first equation\n");
    equation1_fun(&equation1);
    printlist(&equation1);

    printf("Enter the data of the second equation\n");
    equation2_fun(&equation2);
    printlist(&equation2);


}