#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024
#define PAUSE 5

int datalogger();

int main()
{
    while(1)
    {
        system("wget http://www.zamg.ac.at/ogd");
        datalogger();
        system("rm ogd*");
        sleep(PAUSE);
    }
}

int datalogger()
{
    char buf[MAX];
    FILE *datei;
    char *datum, *uhrzeit;
    float temperatur = 0;

    datei = fopen("ogd", "r");
    if(NULL==datei)
    {
        printf("Datei konnte nicht geoeffnet werden!\n");
        return -1;
    }

    while(fgets(buf,MAX,datei) != NULL)
    {
        if(strstr(buf, "Salzburg") != NULL) // Zeile mit Salzburg gefunden
            fputs(buf, stdout);
    }

fclose(datei);

return EXIT_SUCCESS;
}
