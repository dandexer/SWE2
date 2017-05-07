/*
================================================================================================
 Name:          SortArray.c
 Author:        Dominik Andexer
 Description:   Sort an array with 'qsort'
================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define ANZ 5

int a[ANZ] = {34, 4, 55, 23, 6};

// compare function for qsort
int comp(const void *a, const void *b)
{
      return *(int*)a - *(int*)b;
}
    // function to print the sorted array
int ausgabe( int a[ANZ] )
{
    int i;

    for(i=0; i<ANZ; i++)
        printf("%d:   %d\n", i, a[i]);

    return 0;
}

int main()
{
    // print unsorted array
    printf("Unsortiert:\n");
    ausgabe(a);

    // sort with qsort-function
    qsort(a, ANZ, sizeof(int), comp);

    // print sorted array
    printf("\n\nSortiert:\n");
    ausgabe(a);

    return EXIT_SUCCESS;
}
