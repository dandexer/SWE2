#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

// Struktur definieren (enthält Daten als Integer-Werte
// Der Zeiger struct Slist *next zeigt auf eine Adresse des nächsten Elements vom selben Typ.
struct SList
{
    int data;
    struct SList *next;     // Referenz zum nächsten Element
    struct SList *prev;     // Referenz zum vorhergehenden Element
};
typedef struct SList SLIST;

// Header der Liste
struct SList_Header
{
    int len;                // Länge der Liste
    SLIST *first, *last;    // Referenz zum ersten und zum letzten Element
};
typedef struct SList_Header SLIST_HEADER;

SLIST_HEADER *createSList(void);
SLIST *insertFirst(SLIST_HEADER *, int);
SLIST *insertLast(SLIST_HEADER *, int);
void *deleteFirst(SLIST_HEADER *);
void *deleteLast(SLIST_HEADER *);
void pr_SList(SLIST_HEADER *);
void rm_SList(SLIST_HEADER *);
void get_entrySList(SLIST_HEADER *head, int);

#endif // LIST_H_INCLUDED
