#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


typedef struct Element
{
    int data;
    struct Element *link;
} ELEM;

void push(int);
void pop(void);
void showtop(void);
void empty(void);
void ength(void);
void delete(void);
void print(void);


#endif // STACK_H_INCLUDED
