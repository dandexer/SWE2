/*
================================================================================================
 Name:          fifo_main.c
 Author:        Dominik Andexer
 Description:   FIFO-Speicher
================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"

int main()
{
    int auswahl=0, wert=0;

    do
    {
        printf("========================== FIFO | QUEUE ==========================\n\n"\
                "Welche Operation wollen Sie durchfuehren?\n\n"\
                " -1- put\t"\
                " -2- get\t"\
                " -3- last\t"\
                " -4- next\n"\
                " -5- empty\t"\
                " -6- length\t"\
                " -7- print\t"\
                " -8- delete\t"\
                " -9- exit\n\n"\
                "================================================================>> ");
        scanf("%d", &auswahl);

    switch(auswahl)
    {
        case 1:
            printf("Wert hinzufuegen: "); scanf("%d", &wert);
            put(wert);
            break;
        case 2:
            get();
            break;
        case 3:
            last();
            break;
        case 4:
            next();
            break;
        case 5:
            empty();
            break;
        case 6:
            printf("Es sind %d Element(e) im Speicher!\n", length());
            break;
        case 7:
            print();
            break;
        case 8:
            delete();
            break;
        case 9:
            return EXIT_SUCCESS;
        default:
            printf("Falsche Auswahl!\n");
    }
    printf("\n\n\n");
    } while(auswahl != 9);

    return EXIT_SUCCESS;
}
