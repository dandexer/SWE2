#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"

// Globale PTRs die auf den Anfang und auf das Ende der Queue zeigen
// Eingefügt wird bei der Schlange hinten (rear) und entnommen vorne (front)
ELEM *rear = NULL;
ELEM *front = NULL;


// put: Hinzufügen eines neuen Eintrags in den FIFO Speicher
void put(int x)
{
    ELEM *tmp = malloc(sizeof(ELEM));

    tmp->data = x;          // Daten in ELEM einfügen

    if(NULL == rear && NULL == front) // 1. Element wird hinzugefügt
    {
        rear = front = tmp; // rear und front PTR auf das neue Element
        tmp->next = tmp->prev = NULL;
    }
    else
    {
        tmp->next = rear;
        tmp->next->prev = tmp;
        rear = tmp;
    }
}

// get: Holen eines Eintrags aus dem FIFO Speicher
void get(void)
{
    ELEM *tmp = front;

    if(NULL == front)                // wenn kein Element in Schlange
    {
        printf("Speicher leer!\n");
        return;
    }
    else if(front == rear) // wenn 1 Element in Schlange, front und rear PTR auf NULL zeigen lassen
    {
        front = rear = NULL;
        tmp->next = tmp->prev = NULL;
        free(tmp); free(tmp->data);
    }
    else
    {
        front->prev->next = NULL;
        free(tmp->data); free(tmp);
    }
    printf("get erfolgreich!\n");
}

// last: Abfragen des letzten mit put hinzugefügten Eintrags ohne ihn zu entfernen
void last(void)
{
    if(NULL==rear)
    {
        printf("FIFO leer!\n");
        return;
    }
    else
        printf("Letztes hinzugefuegtes Element: %d\n", rear->data);
}

// next: Abfragen des nächsten mit get gelieferten Eintrags ohne ihn zu entfernen
void next(void)
{
    if(NULL==front)
    {
        printf("FIFO leer!\n");
        return;
    }
    else
        printf("Naechstes Element: %d\n", front->data);
}

// empty: Abfragen, ob FIFO Speicher leer ist
void empty(void)
{
    if(NULL == rear && NULL == front) // front und rear PTR NULL = noch kein Element in Warteschlange
        printf("FIFO-Speicher ist leer!\n");
    else
        printf("FIFO-Speicher ist NICHT leer!\n");
}

// length: Abfragen, wie viele Einträge im FIFO Speicher abgelegt sind
int length(void)
{
    ELEM *tmp = rear;
    int count=0;

    while(NULL != tmp)
    {
        tmp = tmp->next;
        count++;
    }
    return count;
}

// Queue drucken
void print(void)
{
    ELEM *tmp = rear;

    if(NULL == rear && NULL == front)
        printf("Speicher leer!\n");

    while(tmp != NULL)
    {
        printf("%d -> ", tmp->data);
        tmp = tmp->next;
    }
    puts("");
}

// delete: Löschen des gesamten FIFO Speichers
void delete(void)
{
    ELEM *tmp = rear;

    if(NULL == rear && NULL == front)
    {
        printf("Speicher leer!\n");
        return;
    }

    while(tmp != NULL)
    {
        get();
        tmp = tmp->next;
    }
    free(tmp);
    printf("Speicher erfolgreich geloescht!\n");
}

