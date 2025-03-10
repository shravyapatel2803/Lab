#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

struct lifo
{
    int st[MAXSIZE];
    int top;
};

typedef struct lifo

    stack;

stack s;
void create(stack *s)
{
    s->top = -1;
}
void push(stack *s,int element)
{
    if (s->top == (MAXSIZE - 1))

    {

        printf("\nStackoverflow");

        exit(-1);
    }

    else

    {

        s->top++;

        s->st[s->top] = element;
    }
}
int main(){
    stack *s ;
    create(s);
    push(s,12);
}