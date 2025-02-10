#include<stdio.h>
#include<stdlib.h>

struct node{
    int expo;
    int coff;
    struct node *next;
};

void equation_fun(struct node **equation) {
    int y = 1;
    struct node *temp, *newnode;
    *equation = NULL;

    while(y){
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter 1 to add another term, 2 to stop: ");
        scanf("%d", &y);
        if(y==1){

            printf("Enter term (coefficient followed by exponent): ");
            scanf("%d %d", &newnode->coff, &newnode->expo);
            newnode->next = NULL;
    
            if (*equation == NULL) {
                *equation = newnode;
            } else {
                temp = *equation;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newnode;
            }
        }
        else if(y==2){
            y=0;
        }
        else{
            printf("try again\n");
        }
        

    }
}

void printlist(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coff, temp->expo);
        if (temp->next != NULL) printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

void add_equations(struct node *eq1, struct node *eq2, struct node **final) {
    *final = NULL;
    struct node *temp1 = eq1, *temp2 = eq2, *temp_final = NULL;

    while (temp1 != NULL && temp2 != NULL) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));

        if (temp1->expo == temp2->expo) {
            newNode->coff = temp1->coff + temp2->coff;
            newNode->expo = temp1->expo;
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->expo > temp2->expo) {
            newNode->coff = temp1->coff;
            newNode->expo = temp1->expo;
            temp1 = temp1->next;
        } else {
            newNode->coff = temp2->coff;
            newNode->expo = temp2->expo;
            temp2 = temp2->next;
        }

        newNode->next = NULL;

        if (*final == NULL) {
            *final = newNode;
            temp_final = newNode;
        } else {
            temp_final->next = newNode;
            temp_final = newNode;
        }
    }

    while (temp1 != NULL) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->coff = temp1->coff;
        newNode->expo = temp1->expo;
        newNode->next = NULL;
        temp_final->next = newNode;
        temp_final = newNode;
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->coff = temp2->coff;
        newNode->expo = temp2->expo;
        newNode->next = NULL;
        temp_final->next = newNode;
        temp_final = newNode;
        temp2 = temp2->next;
    }
}

int main() {
    struct node *equation1 = NULL, *equation2 = NULL, *final_equation = NULL;

    printf("Enter the data for the first equation\n");
    equation_fun(&equation1);
    printlist(equation1);

    printf("Enter the data for the second equation\n");
    equation_fun(&equation2);
    printlist(equation2);

    add_equations(equation1, equation2, &final_equation);
    printf("The result of addition is:\n");
    printlist(final_equation);

    return 0;
}
