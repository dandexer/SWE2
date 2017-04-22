/*
================================================================================================
 Name:          deque_main.c
 Author:        Dominik Andexer
 Description:   Double-ended queue
================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

int main()
{
    int auswahl=0, wert=0;

    do
    {
        printf("========================== DOUBLE-ENDED QUEUE =====================\n\n"\
                "Welche Operation wollen Sie durchfuehren?\n\n"\
                " -1- insert back  | "\
                " -2- remove back\n"\
                " -3- insert front | "\
                " -4- remove front\n"\
                " -5- examine first\t"\
                " -6- examine last\n"\
                " -7- empty\t"\
                " -8- delete\t"\
                " -9- print\t"\
                " -10- exit\n\n"\
                "================================================================>> ");
        scanf("%d", &auswahl);

    switch(auswahl)
    {
        case 1:
            printf("Wert hinzufuegen: "); scanf("%d", &wert);
            insert_element_at_back(wert);
            break;
        case 2:
            remove_element_at_back();
            break;
        case 3:
            printf("Wert hinzufuegen: "); scanf("%d", &wert);
            insert_elment_at_front(wert);
            break;
        case 4:
            remove_element_at_front();
            break;
        case 5:
            examine_rear_element();
            break;
        case 6:
            examine_front_element();
            break;
        case 7:
            empty();
            break;
        case 8:
            delete();
            break;
        case 9:
            print();
            break;
        case 10:
            return EXIT_SUCCESS;
        default:
            printf("Falsche Auswahl!\n");
    }
    printf("\n\n\n");
    } while(auswahl != 10);

    return EXIT_SUCCESS;
}
