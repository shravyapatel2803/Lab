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
// void add_equations(struct node **eq1, struct node **eq2, struct node **final) {
//     *final = NULL; 

//     struct node *temp1 = *eq1;
//     struct node *temp2 = *eq2;
//     struct node *temp_final = NULL;


//     while (temp1 != NULL || temp2 != NULL) {
//         struct node *new_term = (struct node *)malloc(sizeof(struct node));
//         if (new_term == NULL) {
//             perror("Memory allocation failed");
//             exit(EXIT_FAILURE);
//         }
//         new_term->next = NULL;

//         if (temp1 == NULL) { 
//             new_term->coff = temp2->coff;
//             new_term->expo = temp2->expo;
//             temp2 = temp2->next;
//         } else if (temp2 == NULL) { 
//             new_term->coff = temp1->coff;
//             new_term->expo = temp1->expo;
//             temp1 = temp1->next;
//         } else if (temp1->expo == temp2->expo) { 
//             new_term->coff = temp1->coff + temp2->coff;
//             new_term->expo = temp1->expo;
//             temp1 = temp1->next;
//             temp2 = temp2->next;
//             if (new_term->coff == 0) { 
//                 free(new_term);
//                 continue; 
//             }
//         } else if (temp1->expo > temp2->expo) { 
//             new_term->coff = temp1->coff;
//             new_term->expo = temp1->expo;
//             temp1 = temp1->next;
//         } else { 
//             new_term->coff = temp2->coff;
//             new_term->expo = temp2->expo;
//             temp2 = temp2->next;
//         }

//         if (*final == NULL) { 
//             *final = new_term;
//             temp_final = *final;
//         } else { 
//             temp_final->next = new_term;
//             temp_final = new_term;
//         }
//     }
// }

void main(){
    struct node *equation1=NULL,*equation2=NULL,*final_equation=NULL;
    printf("Enter the data of the first equation\n");
    equation1_fun(&equation1);
    printlist(&equation1);

    printf("Enter the data of the second equation\n");
    equation2_fun(&equation2);
    printlist(&equation2);


}