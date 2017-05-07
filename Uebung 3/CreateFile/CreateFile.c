/*
================================================================================================
 Name:          CreateFile.c
 Author:        Dominik Andexer
 Description:   Schreiben Sie ein Programm mit dem Namen CreateFile, welche eine Datei mit
                zufälligen Zahlen erstellt. Das Programm soll folgende Optionen über die
                Kommandozeile unterstützen:

================================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i=0, j=0, anzahl = 100, zahlenbereich = 100;
    int *zahlen;
    FILE *datei;
    void showhelp();

    if( argc==1 || strcmp(argv[i], "-h") == 0 ) // wenn keine Argumente eingegeben wurden oder -h erscheint Hilfe
    {
        showhelp();
        return;
    }

    // Prüft, welche Argumente eingegeben wurden (Reihenfolge egal)
    for(i=1; i < argc; i++)
    {

        if( strcmp(argv[i],"-n") == 0 ) // wenn -n eingegeben wurde
        {
            anzahl = atoi(argv[i+1]);
            i++;
        }
        else if( strcmp(argv[i],"-r") == 0 ) // wenn -r eingegeben wurde
        {
            zahlenbereich = atoi(argv[i+1]);
            i++;
        }
        else if( strstr(argv[i], ".txt") != NULL) // wenn die Ausgabedatei (.txt) eingegeben wurde
        {
            datei = fopen(argv[i], "w+t");
            if(NULL == datei)
                printf("Datei konnte nicht geoeffnet werden!\n");
        }
    }

    // Zahlen in Datei schreiben
    srand(time(NULL));
    zahlen = malloc(anzahl*sizeof(int));

    for(i=0; i < anzahl; i++)
    {
        zahlen[i] = rand() % zahlenbereich;
        fprintf(datei,"%d\n", zahlen[i]);
    }
    fclose(datei);
    printf("Zahlen generiert und Datei gespeichert!\n");

    return EXIT_SUCCESS;
}

void showhelp()
{
    printf("Aufruf: CreateFile [Option] File\n"\
           "Option Beschreibung:\n"\
           "\t-h Hilfe\n"\
           "\t-n Anzahl der Zahlen (default 100)\n"\
           "\t-r Zahlenbereich (default = 100)\n"\
           "Aufrufbeispiel:\n"\
           "$ ./CreateFile -n 3 -r 1000 ausgabe.txt\n\n");
}

