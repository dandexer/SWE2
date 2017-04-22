#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

// Globale Pointer

ELEM *rear = NULL, *front = NULL;

// insert_element_at_back: Hinzufügen eines neuen Eintrags in den DEQUEUE Speicher
void insert_element_at_back(int data)
{
    ELEM *tmp = malloc(sizeof(ELEM));

    if(NULL==rear && NULL==front)        // Deque enthält noch keine Elemente
    {
        tmp->data = data;
        rear = front = tmp;
        tmp->next = tmp->prev = NULL;
    }
    else
    {
        tmp->data = data;
        tmp->next = rear;
        tmp->prev = NULL;
        tmp->next->prev = tmp;
        rear = tmp;
    }
}

// remove_element_at_back: Holen eines Eintrags aus dem DEQUEUE Speicher
void remove_element_at_back(void)
{
    ELEM *tmp = rear;

    if(tmp==NULL)
    {
        printf("Deque leer!\n");
        return;
    }
    else if(front == rear)
    {
        front = rear = NULL;
        tmp->next = tmp->prev = NULL;
        free(tmp); free(tmp->data);
    }
    else
    {
        rear->next->prev = NULL;
        rear = rear->next;
        free(tmp); free(tmp->data);
    }

    printf("Element entfernt!\n");
}

//insert_element_at_front: Hinzufügen eines neuen Eintrags in den DEQUEUE Speicher
void insert_elment_at_front(int data)
{
    ELEM *tmp = malloc(sizeof(ELEM));

    if(NULL==rear && NULL==front)        // Deque enthält noch keine Elemente
    {
        tmp->data = data;
        rear = front = tmp;
        tmp->prev = tmp->next = NULL;
    }
    else
    {
        tmp->data = data;
        tmp->prev = front;
        tmp->next = NULL;
        tmp->prev->next = tmp;
        front = tmp;
    }
}

// remove_element_at_front: Holen eines Eintrags aus dem DEQUEUE Speicher
void remove_element_at_front(void)
{
    ELEM *tmp = front;

    if(tmp==NULL)
    {
        printf("Deque leer!\n");
        return;
    }
    else if(front == rear)
    {
        front = rear = NULL;
        tmp->next = tmp->prev = NULL;
        free(tmp); free(tmp->data);
    }
    else
    {
        front->prev->next = NULL;
        front = front->prev;
        free(tmp); free(tmp->data);
    }

    printf("Element entfernt!\n");
}

// examine_first_element: Abfragen des ersten Element
void examine_rear_element(void)
{
    if(NULL==rear)
    {
        printf("Deque leer!\n");
        return;
    }
    printf("Erstes Element: %d\n", rear->data);
}

// examine_last_element: Abfragen des letzten Element
void examine_front_element(void)
{
    if(NULL==front)
    {
        printf("Deque leer!\n");
        return;
    }
    printf("Letztes Element: %d\n", front->data);
}

// empty: Abfragen, ob DEQUEUE Speicher leer ist
void empty(void)
{
    if(NULL==rear && NULL==front)
        printf("Deque ist leer!\n");
    else
        printf("Deque ist NICHT leer!\n");
}

// print: Alle Elemente drucken
void print(void)
{
    ELEM *tmp = rear;

    if(NULL==rear && NULL==front)
        printf("Deque leer!\n");

    while(tmp != NULL)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}

// delete: Löschen des gesamten DEQUEUE Speichers
void delete(void)
{
    ELEM *tmp = rear;

    while(rear != NULL)
    {
        remove_element_at_back();
    }
    free(tmp);

    printf("Datenstruktur erfolgreich geloescht!\n");
}
