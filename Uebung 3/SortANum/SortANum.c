/*
================================================================================================
 Name:          SortANum.c
 Author:        Dominik Andexer
 Description:   program takes Integers from the CLI and outputs it sorted to stdout
================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])   // char *argv[] --> Array von Zeigern, **argv ist dasselbe
{
    int i;
    int *p;

// show help when "--help" or no numbers entered
    if(argc == 1 || strcmp(argv[1],"--help")==0 )
    {
        showhelp();
    }
    else
    {
        p = malloc(argc * sizeof(int));
        if(NULL==p)
        {
            printf("Kein Speicher reserviert!\n");
            return -1;
        }

    // read argv[] and put it in array p
        for(i=1; i <= argc-1; i++)
            p[i-1] = atoi(argv[i]);       // atoi = ASCII to Integer

    // compare function
        int comp(const void *a, const void *b) // 2 Zeiger werden übergeben, Funktion liefert zurück, ob man tauschen soll
        {
            return ( *(int*)a - *(int*)b );
        }
    // sort the array
        qsort(p, argc-1, sizeof(int), comp);

    // print sorted array
        printf("Sorted: ");
            for(i=0; i<argc-1; i++)
                printf("%d ", p[i]);
    }
    return EXIT_SUCCESS;
}

void showhelp(void)
{
    printf("The Program takes unsigned Integers from the CLI\n"\
           "and outputs it sorted to stdout.\n\n"\
          "For example:\n"\
          "$ ./SortANum 17 12 23 5\n"\
          "Sorted: 5 12 17 23\n\n");
}
