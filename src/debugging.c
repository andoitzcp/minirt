#include "minirt.h"

void print_ds_rawl(t_rawlines **head)
{
    char *s;
    t_rawlines *rawl;
    int i;
    int j;

    printf("Printing rawlines for ds ($ = '\\n'): %p\n", head);
    i = 0;
    rawl = *head;
    while(rawl)
    {
        s = ft_strdup(rawl->line);
        j = 0;
        while (s[j] != '\0')
        {
            if (s[j] == '\n')
                s[j] = '$';
            j++;
        }
        printf("\t%d: %s, %d, %p\n", i++, rawl->line, rawl->elid, rawl->line);
        free(s);
        rawl = rawl->next;
    }
    printf("Finished printing rawlines for ds: %p\n", head);
}
