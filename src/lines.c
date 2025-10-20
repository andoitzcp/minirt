#include "minirt.h"

char ***split_line(char *s)
{
    size_t len;
    size_t i;
    void ***line;

    len = ft_strlen(s);
    if (s[len - 1] == '\n')
        s[len - 1] = '\0';
    line = (void ***)ft_split(s, ' ');
    i = 0;
    while ((char *)line[i] != NULL)
    {
        line[i] = (void **)ft_split((char *)line[i], ',');
        i++;
    }
    return ((char ***)line);
}

t_line *build_line_node(t_data *data, char ***line, int type)
{
    t_line *node;

    node = ft_calloc(1, sizeof(t_line));
    if (node == NULL)
        ft_exit(data, ERRORS009);
    node->type = type;
    node->content = line;
    node->next = NULL;
    return (node);
}

void append_line_node(t_line **head, t_line *node)
{
    t_line *current;

    current = *head;
    if (current == NULL)
    {
        *head = node;
        return ;
    }
    while (current->next != NULL)
        current = current->next;
    current->next = node;
    return ;
}

void process_line(t_data *data, char *s)
{
    int i;
    char ***line;
    t_line *node;

    i = 0;
    while (data->re_el_types[i] != NULL)
    {
        if (match(data->re_el_types[i++], s) == 0)
            continue ;
        line = split_line(s);
        node = build_line_node(data, line, i - 1);
        if (i - 1 != ELID_BLANK_LINE)
            append_line_node(&(data->lines), node);
        return ;
    }
    ft_exit(data, ERRORS007);
    return ;
}
