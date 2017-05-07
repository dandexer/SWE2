/*
================================================================================================
 Name:          SortFile.c
 Author:        Dominik Andexer
 Description:   Schreiben Sie ein Programm mit dem Namen SortFile, welches ein File mit
                Zahlen liest und sortiert ausgibt. Es soll die Bibliotheksfunktion qsort()
                eingesetzt werden.
================================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int comp(void const *a, void const *b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int i=0, anzahl=1, ch=0;
    int *zahlen;
    char buf[100];
    FILE *datei = fopen("zahlen.txt", "rt");

    // Anzahl Zahlen ermitteln
    while( (ch=fgetc(datei)) != EOF )
        if(ch == '\n') anzahl++;

    rewind(datei);
    zahlen = malloc(anzahl*sizeof(int));

    for(i=0; i < anzahl; i++)
    {
        fgets(buf, 100, datei);
        zahlen[i] = atoi(buf);
    }
    // Sortieren mit qsort
    qsort(zahlen, anzahl, sizeof(int), comp);

    // Sortierte Ausgabe
    printf("Sortierte Ausgabe der Datei:\n");
    for(i=0; i < anzahl; i++)
    {
        printf("%d\n", zahlen[i]);
    }

    return EXIT_SUCCESS;
}
