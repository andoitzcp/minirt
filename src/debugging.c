#include "minirt.h"

void print_ds_rawl(t_rawlines **head)
{
    t_rawlines *rawl;
    int i;
    int j;

    printf("Printing rawlines for ds ($ = '\\n'): %p\n", head);
    i = 0;
    rawl = *head;
    while(rawl)
    {
        j = 0;
        while (rawl->line[j] != '\0')
        {
            if (rawl->line[j] == '\n')
                rawl->line[j] = '$';
            j++;
        }
        printf("\t%d: %s, %d, %p\n", i++, rawl->line, rawl->elid, rawl->line);
        rawl = rawl->next;
    }
    printf("Finished printing rawlines for ds: %p\n", head);
}
