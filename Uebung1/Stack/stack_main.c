/*
================================================================================================
 Name:          stack_main.c
 Author:        Dominik Andexer
 Description:   stack
================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    int auswahl=0, wert=0;

    do
    {
        printf("========================== STACK ==========================\n\n"\
                "Welche Operation wollen Sie durchfuehren?\n\n"\
                " -1- push\t"\
                " -2- pop\t"\
                " -3- top\t"\
                " -4- empty\n"\
                " -5- length\t"\
                " -6- delete\t"\
                " -7- print\t"\
                " -8- Exit\n\n"\
                "=========================================================>> ");
        scanf("%d", &auswahl);

    switch(auswahl)
    {
        case 1:
            printf("Wert hinzufuegen: "); scanf("%d", &wert);
            push(wert);
            break;
        case 2:
            pop();
            break;
        case 3:
            showtop();
            break;
        case 4:
            empty();
            break;
        case 5:
            length();
            break;
        case 6:
            delete();
            break;
        case 7:
            print();
            break;
        case 8:
            return EXIT_SUCCESS;
    }
    printf("\n\n\n");
    } while(auswahl != 8);

    return EXIT_SUCCESS;
}
