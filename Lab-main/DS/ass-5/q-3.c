#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node* next;
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
            scanf("%d %d", &newnode->coeff, &newnode->exp);
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
void insertTerm(struct node** head, int coeff, int exp) {
    // struct node* newNode ;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    struct node* temp = *head;

    if (*head == NULL || (*head)->exp < exp) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    while (temp->next != NULL && temp->next->exp > exp) {
        temp = temp->next;
    }

    if (temp->next != NULL && temp->next->exp == exp) {
        temp->next->coeff += coeff;
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

struct node* multiplyPolynomials(struct node* poly1, struct node* poly2) {
    struct node* result = NULL;
    struct node* p1 = poly1;

    while (p1 != NULL) {
        struct node* p2 = poly2;
        while (p2 != NULL) {
            insertTerm(&result, p1->coeff * p2->coeff, p1->exp + p2->exp);
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return result;
}

void displayPoly(struct node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        if (poly->next != NULL) {
            printf(" + ");
        }
        poly = poly->next;
    }
    printf("\n");
}

void getPolynomial(struct node** poly) {
    int n, coeff, exp;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent (coeff exp): ");
        scanf("%d %d", &coeff, &exp);
        insertTerm(poly, coeff, exp);
    }
}

int main() {
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;
    struct node* result = NULL;

    printf("Enter the first polynomial:\n");
    equation_fun(&poly1);
    printf("Enter the second polynomial:\n");
    equation_fun(&poly2);

    printf("Polynomial 1: ");
    displayPoly(poly1);
    printf("Polynomial 2: ");
    displayPoly(poly2);

    result = multiplyPolynomials(poly1, poly2);

    printf("Result (Polynomial 1 * Polynomial 2): ");
    displayPoly(result);

    return 0;
}
