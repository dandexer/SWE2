#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED

typedef struct Elem
{
    int data;           // Daten
    int len;
    struct Elem *next;  // PTR auf nächstes Element
    struct Elem *prev;  // PTR auf vorgehendes Element

} ELEM;                 // Alias für struct Elem

// Prototypen:
void insert_element_at_back(int);
void remove_element_at_back(void);
void insert_elment_at_front(int);
void remove_element_at_front(void);
void examine_rear_element(void);
void examine_front_element(void);
void empty(void);
void print(void);
void delete(void);



#endif // DEQUE_H_INCLUDED
