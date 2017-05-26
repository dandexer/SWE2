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
    FILE *datei = fopen("ogd", "rt");
    FILE *logfile = fopen("logfile.ini", "at");

    char datum[MAX], uhrzeit[MAX];
    float temp = 0;

    if(NULL==datei || NULL==logfile)
    {
        printf("Datei konnte nicht geoeffnet werden!\n");
        return -1;
    }

    while(fgets(buf,MAX,datei) != NULL)
    {
        if(strstr(buf, "Salzburg") != NULL) // Zeile mit Salzburg gefunden
            sscanf(buf,"%*i;\"%*[^\"]\";%*i;\"%[^\"]\";\"%[^\"]\";%f%*[^\n]", &datum, &uhrzeit, &temp);
    }
    fprintf(logfile, "Temperatur in Salzburg am %s um %s Uhr: %.2f °C\n", datum, uhrzeit, temp);

fclose(datei); fclose(logfile);

return EXIT_SUCCESS;
}
