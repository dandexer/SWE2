#ifndef FIFO_H_INCLUDED
#define FIFO_H_INCLUDED

typedef struct Queue
{
    int data;           // Daten
    struct Queue *next; // PTR zum nächsten Element
    struct Queue *prev; // PTR zum vorgehenden Element

} ELEM;

// Prototypen der Funktionen
void put(int);
void get(void);
void last(void);
void next(void);
void empty(void);
int length(void);
void print(void);
void delete(void);



#endif // FIFO_H_INCLUDED
