/*
================================================================================================
 Name:          tree_main.c
 Author:        Dominik Andexer
 Description:   Binary Search Tree
================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void)
{
    int auswahl=0, zahl=0, key=0;
    KNOTEN *root = NULL; // root-PTR am Anfang auf NULL setzten

    do
    {
        printf("========================== BINARY TREE =====================\n\n"\
                "Welche Operation wollen Sie durchfuehren?\n\n"\
                " -1- Einfuegen\n"\
                " -2- Trav.inorder   "\
                " -3- Trav.preorder   "\
                " -4- Trav.postorder\n"\
                " -5- Suchen\n"\
                " -6- Beenden\n"\
                "==========================================================>> ");
        scanf("%d", &auswahl);

        switch(auswahl)
        {
        case 1:
            printf("Welchen Wert wollen Sie einordnen?\n"); scanf("%d", &zahl);
            root = einordnen(root, zahl);
            break;
        case 2:
            inorder_print(root);
            printf("\n\n\n");
            break;
        case 3:
            preorder_print(root);
            printf("\n\n\n");
            break;
        case 4:
            postorder_print(root);
            printf("\n\n\n");
            break;
        case 5:
            printf("Welchen Wert wollen Sie suchen? "); scanf("%d", &key);
            suche(root, key);
        case 6:
            return EXIT_SUCCESS;
        default:
            printf("Falsche Auswahl!\n");
        }

    } while(auswahl != 6);

    return EXIT_SUCCESS;
}
