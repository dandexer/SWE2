#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 255

typedef struct ini_elem
{
    char *key;              // Schluessel
    char *value;            // Wert
    struct ini_elem *next;
} INI_ELEM;

// Globaler PTRs zum Managen der Liste
INI_ELEM *first = NULL;
INI_ELEM *last = NULL;

// Prototypen
einfuegen(char*, char*);
print();

int main()
{
    char buffer[MAX];
    char *key, *value;

    FILE *datei = fopen("datenlogger.ini", "rt");
    if(NULL==datei)
        printf("Datei konnte nicht geoeffnet werden!\n");

   while ( fgets(buffer, MAX, datei) != NULL )
    {
        // Kommentare mit ; und Sektions werden überlesen
        if(buffer[0]== ';' || buffer[0] == '[')
            continue;

        // Kommentare mit ; und Sektions werden überlesen
        if(buffer[0]== ';' || buffer[0] == '[')
            continue;

        // Aufteilen der eingelesenen Zeile vor/nach dem = Zeichen
        key = strtok(buffer, "=");
        value = strtok(NULL, "=");

        // Übergabe der Werte an die Funktion einfuegen
        einfuegen(key, value);
    }

    // Funktion zum Drucken
    print();

    fclose(datei);
    return EXIT_SUCCESS;
}

// Funktion zum Einfügen eines Key=Value (einfach verkettete Liste)
einfuegen(char *k, char *v)
{
    INI_ELEM *new = malloc(sizeof(INI_ELEM));
    if(NULL==new)
        printf("Fehler bei malloc!\n");

    if(first == NULL)
    {
        new->key = k;
        new->value = v;
        first = last = new;
        new->next = NULL;
    }
    else
    {
        new->key = k;
        new->value = v;

        last->next = new;
        last = new;
        new->next = NULL;
    }
}
// Funktion zum Ausgeben der eingelesenen Werte auf stdout
print()
{
    INI_ELEM *print = first;

    while(print->next != NULL)
    {
        printf("%s=%s\n", print->key, print->value);
        print = print->next;
    }
    printf("%s=%s\n", print->key, print->value);
}
