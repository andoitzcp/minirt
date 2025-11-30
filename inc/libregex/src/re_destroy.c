#include "libregex.h"

void re_destroy(t_re **re)
{
    t_re *node;
    t_re *p;

    node = *re;
    while (node)
    {
        p = node;
        node = node->next;
        free(p);
        p = NULL;
    }
    free(re);
    re = NULL;
    return ;
}
