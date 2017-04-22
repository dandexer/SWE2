/*
================================================================================================
 Name:          list_main.c
 Author:        Dominik Andexer
 Description:   doubly linked list
================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    int auswahl=0, wert=0;
    SLIST_HEADER *mylist = createSList();

    do
    {
        printf("============DOUBLY LINKED LIST============\n\n"\
                "Welche Operation wollen Sie durchfuehren?\n\n"\
                " -1- InsertFirst\t"\
                " -2- InsertLast\t\t"\
                " -3- DeleteFirst\n"\
                " -4- DeleteLast\t\t"\
                " -5- PrintList\t\t"\
                " -6- RemoveList\n"\
                " -7- Get_entryList\t"\
                " -8- Exit\n");
        scanf("%d", &auswahl);

    switch(auswahl)
    {
        case 1:
            printf("Wert hinzufuegen: "); scanf("%d", &wert);
            insertFirst(mylist, wert);
            break;
        case 2:
            printf("Wert hinzufuegen: "); scanf("%d", &wert);
            insertLast(mylist, wert);
            break;
        case 3:
            deleteFirst(mylist);
            break;
        case 4:
            deleteLast(mylist);
            break;
        case 5:
            pr_SList(mylist);
            break;
        case 6:
            rm_SList(mylist);
            break;
        case 7:
            printf("Welches Element drucken? "); scanf("%d", &wert);
            get_entrySList(mylist, wert);
            break;
        case 8:
            return EXIT_SUCCESS;
    }
    printf("\n\n\n");
    } while(auswahl != 8);

    return EXIT_SUCCESS;
}
