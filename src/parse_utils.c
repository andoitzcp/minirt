#include "minirt.h"

int get_element_id(char *s)
{
    if (ft_strncmp(s, EL_BLANK_LINE_ID, ft_strlen(EL_BLANK_LINE_ID)) == 0)
        return (ELID_BLANK_LINE);
    else if (ft_strncmp(s, EL_CAMERA_ID, ft_strlen(EL_CAMERA_ID)) == 0)
        return (ELID_C);
    else if (ft_strncmp(s, EL_LIGHT_ID, ft_strlen(EL_LIGHT_ID)) == 0)
        return (ELID_L);
    else if (ft_strncmp(s, EL_SPHERE_ID, ft_strlen(EL_SPHERE_ID)) == 0)
        return (ELID_SP);
    else if (ft_strncmp(s, EL_PLANE_ID, ft_strlen(EL_PLANE_ID)) == 0)
        return (ELID_PL);
    else if (ft_strncmp(s, EL_SQUARE_ID, ft_strlen(EL_SQUARE_ID)) == 0)
        return (ELID_SQ);
    else if (ft_strncmp(s, EL_CYLINDER_ID, ft_strlen(EL_CYLINDER_ID)) == 0)
        return (ELID_CY);
    else if (ft_strncmp(s, EL_TRIANGLE_ID, ft_strlen(EL_TRIANGLE_ID)) == 0)
        return (ELID_TR);
    else
        return (ELID_INVALID);
}

void classify_raw_content_into_elements(t_rawlines **head)
{
    t_rawlines *current;

    current = *(head);
    while (current != NULL)
    {
        current->line = ft_strtrim(current->line, WS_CHARS);
        current->elid = get_element_id(current->line);
        current = current->next;
    }
    return ;
}

void trim_raw_content_ws_nodes(t_rawlines **head)
{
    t_rawlines *current;
    t_rawlines *tmp;

    current = *(head);
    while (current->next != NULL)
    {
        if (current->next->elid != ELID_BLANK_LINE)
        {
            current = current->next;
            continue ;
        }
        tmp = current->next->next;
        free(current->next);
        current->next = tmp;
    }
    return ;
}

int8_t has_raw_content_invalid_lines(t_rawlines **head)
{
    t_rawlines *current;

    current = *(head);
    while (current != NULL)
    {
        if (current->next->elid != ELID_INVALID)
            return (1);
        current = current->next;
    }
    return (0);
}

uint get_element_qty(t_rawlines **head)
{
    uint i;
    t_rawlines *current;

    i = 0;
    current = *head;
    while (current != NULL)
    {
        current = current->next;
        i++;
    }
    return (i);
}

void append_rawline_node(t_data *data, char *content)
{
    t_rawlines **head;
    t_rawlines *current;
    t_rawlines *node;

    head = data->rawl;
    node = malloc(sizeof(t_rawlines));
    if (!node)
        ft_exit(data, ERRORS001);
    data->emf |= EMF_RAWL;
    node->line = content;
    node->next = NULL;
    current = *head;
    if (current == NULL)
    {
        current = node;
        return ;
    }
    while (current->next != NULL)
        current = current->next;
    current = node;
    return ;
}
