#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
//Globaler top-Pointer, der auf das aktuelle ELEM zeigt (Am Anfang auf NULL)
ELEM *top = NULL;

// Element hinzufügen
void push(int x)
{
    ELEM *tmp = malloc(sizeof(ELEM));

    tmp->data = x; // daten einfügen
    tmp->link = top; // Neues Element zeigt auf bisheriges TOP
    top = tmp; // neues TOP auf das neue Element
}
// Element entfernen
void pop()
{
    ELEM *tmp;
    if(NULL == top) return;

    tmp = top; // top zeigt auf das aktuelle element / wird tmp zugewiesen
    top = top->link; // top zeigt auf link
    free(tmp); free(tmp->data); // tmp und Daten werden gelöscht (aktuelles element)
}
// Das letzte hinzugefügte Element anzeigen, jedoch nicht entfernen
void showtop()
{
    if(NULL == top)
    {
        printf("Stack ist leer!\n");
        return NULL;
    }
    else
        printf("Top-Element: %d\n", top->data);
}
// Abfragen, ob LIFO Speicher leer ist
void empty()
{
    ELEM *tmp;

    if(NULL == top)
        printf("LIFO-Speicher ist leer!\n");
    else
        printf("LIFO-Speicher ist nicht leer!\n");
}
// Anzahl der vorhandenen Elemente zählen
void length()
{
    ELEM *tmp = top;
    int count=0;

    while(tmp != NULL)
    {
        count++;
        tmp = tmp->link;
    }
    printf("Es sind %d Elemente im Stack!\n", count);
}
// Stack löschen
void delete()
{
    while(top != NULL)
    {
        pop();
    }
    printf("Datenstruktur geloescht!\n");
}
// Stack ausgeben
void print()
{
    ELEM *tmp = top;

    if(NULL == tmp)
    {
        printf("Stack ist leer!\n");
        return;
    }

    while(tmp!= NULL)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->link;
    }
}



