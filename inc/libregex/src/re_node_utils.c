#include "libregex_priv.h"

uint8_t check_re_node(t_re *node)
{
    if (node->type == T_NOTVALID)
        return (1);
    return (node->minc > node->maxc && node->maxc != -1);
}

void init_re_node(t_re *node)
{
    //node->type = 0;
    //node->c = 0;
    node->minc = -1;
    node->maxc = -1;
    //node->rawlen = 0;
    //node->next = 0;
}

t_re *build_re_node(char *s)
{
    t_re *node;

    node = ft_calloc(sizeof(t_re), 1);
    if (!node)
        return (NULL);
    init_re_node(node);
    get_node_type(node, s);
    get_node_c(node, s);
    if (get_node_cs(node, s) != 0)
        return (free(node), NULL);
    if (get_node_minc(node, s) != 0)
        return (free(node), NULL);
    if (get_node_maxc(node, s) != 0)
        return (free(node), NULL);
    if (check_re_node(node) != 0)
        return (free(node), NULL);
    node->next = NULL;
    return(node);
}

void append_re_node(t_re **head, t_re *node)
{
    t_re *current;

    current = *head;
    if (current == NULL)
    {
        *head = node;
        return ;
    }
    while (current->next != NULL)
        current = current->next;
    current->next = node;
}
