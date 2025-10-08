#include "libregex.h"
#include "libregex_priv.h"

t_re **re_new(char *s)
{
    t_re **head;
    t_re *node;
    size_t i;

    head = malloc(sizeof(t_re *));
    if (!head)
        return(perror("Malloc error"), NULL);
    *head = NULL;
    i = 0;
    while (s[i] != '\0')
    {
        node = build_re_node(s + i);
        if (node == NULL)
            return (perror("not a valid regex"), NULL);
        append_re_node(head, node);
        i += node->rawlen;
    }
    convert_delimiters(head);
    return (head);
}
