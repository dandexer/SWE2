#include <stdio.h>
#include <stdlib.h>

// Liste drucken (ITERATIV)
void pr_SList(SLIST_HEADER *head, FILE *device)
{
    rewind(device);
    int i = 0;
    SLIST *elem = head->first;

    if(head->len == 0)
        printf("Liste ist leer!\n");

    else
    {
        for(i=0; i < head->len; i++)
        {
            printf("%d. Element:\t%d\t(Adr. %p)\n", i+1, elem->data, elem);
            fprintf(device, "%d. Element:\t%d\t(Adr. %p)\n", i+1, elem->data, elem);
            elem = elem->next;
        }
    }
    fclose(device);
}

// Liste drucken (REKURSIV)
void pr_SList(SLIST_HEADER *head, FILE *device)
{
    rewind(device);
    int i = 0;
    SLIST *elem = head->first;

    if(head->len == 0)
    {
        printf("Liste ist leer!\n");
        return;
    }

    if(elem->next != NULL)
    {

        printf("%d. Element:\t%d\t(Adr. %p)\n", i+1, elem->data, elem);
        fprintf(device, "%d. Element:\t%d\t(Adr. %p)\n", i+1, elem->data, elem);

        SLIST_HEADER *head_new = head;
        head_new->first = head->first->next;
        i++;
        pr_SList(head_new, device);
    }
}
