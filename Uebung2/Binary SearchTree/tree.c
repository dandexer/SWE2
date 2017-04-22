#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// Einfügen
KNOTEN *einordnen(KNOTEN *elem, int data)
{
    if(elem == NULL) // wenn Baum ist leer (Root-Zeiger aus tree_main.c noch auf NULL
    {
        elem = malloc(sizeof(KNOTEN));
            if(NULL==elem)
            {
                fprintf(stderr, "Unable to allocate memory\n");
                return EXIT_FAILURE;
            }

        elem->wert = data;
        elem->links = elem->rechts = NULL;
    }
    else
    {
        if(data <= elem->wert) // neue Daten kleiner => links einfügen
            elem->links = einordnen(elem->links, data);
        else // neue Daten größer => rechts einfügen
            elem->rechts = einordnen(elem->rechts, data);
    }
    return elem;
}
// Traversieren/Drucken
void inorder_print(KNOTEN *elem) // L W R
{
    if(NULL==elem)
        return;
    else
    {
        inorder_print(elem->links);
        printf("%d -> ", elem->wert);
        inorder_print(elem->rechts);
    }
}

void preorder_print(KNOTEN *elem) // W L R
{
    if(NULL==elem)
        return;
    else
    {
        printf("%d -> ", elem->wert);
        preorder_print(elem->links);
        preorder_print(elem->rechts);
    }
}

void postorder_print(KNOTEN *elem) // L R W
{
    if(NULL==elem)
        return;
    else
    {
        postorder_print(elem->links);
        postorder_print(elem->rechts);
        printf("%d -> ", elem->wert);
    }
}

// Suchen
KNOTEN *suche(KNOTEN *elem, int key)
{
    if(elem==NULL)
    {
        fprintf(stderr,"Element nicht gefunden!\n\n");
        return NULL;
    }

    if(elem->wert == key) // Element gefunden
    {
        printf("Element gefunden!\n");
        return elem;
    }

    else if(elem->wert >= key)
        return suche(elem->links, key); // suchen liefert Adresse und wir geben sie gleich weiter

    else
        return suche(elem->rechts, key);
}
