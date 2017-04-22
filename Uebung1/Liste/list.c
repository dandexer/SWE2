#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Liste erstellen
SLIST_HEADER *createSList(void)
{
    SLIST_HEADER *new = malloc(sizeof(SLIST_HEADER));
    if(NULL==new) return NULL;

    new->len = 0;       // Länge der Liste ist am Anfang 0
    new->first = NULL;  // am Anfang ist das erste und das letzte Element leer (NULL)
    new->last = NULL;

    return new;
}
// Vorne einfügen
SLIST *insertFirst(SLIST_HEADER *head, int data)
{
    SLIST *new = malloc(sizeof(SLIST));
    if(NULL == new) return NULL;

    if(head->len == 0) // Liste noch leer
    {
        new->data = data;
        new->next = NULL;
        new->prev = NULL;

        head->len++;
        head->first = new;
        head->last = new;

        return new;
    }
    else // Liste enthält bereits Elemente
    {
        new->data = data;
        new->prev = NULL;
        new->next = head->first;
        new->next->prev = new;

        head->len++;
        head->first = new;

    return new;
    }
}
// Hinten einfügen
SLIST *insertLast(SLIST_HEADER *head, int data)
{
    SLIST *new = malloc(sizeof(SLIST));
    if(NULL == new) return NULL;

    if(head->len == 0)
    {
        new->data = data;
        new->next = NULL;
        new->prev = NULL;

        head->len++;
        head->first = new;
        head->last = new;

        return new;
    }
    else
    {
        new->data = data;
        new->next = NULL;
        new->prev = head->last;
        new->prev->next = new;

        head->len++;
        head->last = new;

        return new;
    }
}
// Vorne löschen
void *deleteFirst(SLIST_HEADER *head)
{
    SLIST *elem = head->first;
    if(head->len == 0) return NULL;

    if(head->len <= 1) // wenn nur 1 Element vorhanden
    {
        head->len = 0;
        head->first = NULL;
        head->last = NULL;
    }
    else
    {
        head->first = elem->next;
        elem->next = NULL;
        head->len--;
    }
}
// Hinten löschen
void *deleteLast(SLIST_HEADER *head)
{
    SLIST *elem = head->last;
    if(head->len == 0) return NULL;

    if(head->len <= 1) // wenn nur 1 Element vorhanden
    {
        head->len = 0;
        head->first = NULL;
        head->last = NULL;
    }
    else
    {
        head->last = elem->prev;
        elem->prev = NULL;
        head->len--;
    }
}
// Liste drucken
void pr_SList(SLIST_HEADER* aList, FILE* device)
{
int i;
SLIST *node;

node= aList->first;
for (i=1; i<=aList->len;i++){
   fprintf(device,"%6d\t%s\n",i,node->data);
   node= node->next;
   }
}

void pr_SList_rek(SLIST_HEADER* aList, FILE* device)
{
    int i;
    SLIST *node;

    node = aList->first;

    if(aList->len > 0)
    {
        fprintf(device,"%6d\t%s\n", i, node->data);
        i++;
        node=node->next;

    }
}



void pr_SList(SLIST_HEADER *head)
{
    int i = 0;
    SLIST *elem = head->first;

    if(head->len == 0)
        printf("Liste ist leer!\n");

    else
    {
        for(i=0; i < head->len; i++)
        {
            printf("%d. Element:\t%d\t(Adr. %p)\n", i+1, elem->data, elem);
            elem = elem->next;
        }
    }
}


// Liste löschen
void rm_SList(SLIST_HEADER *head)
{
    SLIST *del;

    while( head->len > 0)
    {
        deleteFirst(head);
        free(del->data); free(del);
    }
}
// bestimmtes Listenelement ausgeben
void get_entrySList(SLIST_HEADER *head, int n)
{
    int i=0;
    SLIST *elem = head->first;

    if(head->len == 0)
    {
        printf("Liste leer!\n");
        return NULL;
    }
    if(head->len < n)
    {
        printf("Element nicht vorhanden!\n", n);
        return NULL;
    }
    else
    {
        for(i=0; i <= n; i++)
        {
        elem = elem->next;
        }
        printf("%d. Element:\t%d\n", i+1, elem->data);
    }
}
