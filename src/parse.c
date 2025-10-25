#include "minirt.h"

static void alloc_els(t_data *data)
{
    t_line *node;
    size_t i;

    node = data->raw.lines;
    i = 0;
    while (node != NULL)
    {
        i++;
        node = node->next;
    }
    data->raw.els = ft_calloc(i, sizeof(t_elements *) + 1);
    data->raw.nels = (uint)i;
}

static t_elements *build_element_node(t_data *data, char ***line, int type)
{
    t_elements *node;

    node = ft_calloc(1, sizeof(t_elements));
    if (node == NULL)
        ft_exit(data, ERRORS011);
    if (type == ELID_SP)
        get_sphere_data(data, (t_raw_sphere *)&(node->relda.sp), line);
    if (type == ELID_PL)
        get_plane_data(data, (t_raw_plane *)&(node->relda.pl), line);
    if (type == ELID_CY)
        get_cylinder_data(data, (t_raw_cylinder *)&(node->relda.cy), line);
    return (node);
}

static void store_file_data(t_data *data)
{
    t_line *node;
    t_elements **els;
    size_t i;

    els = data->raw.els;
    node = data->raw.lines;
    i = 0;
    while (node != NULL)
    {
        if (node->type == ELID_A)
            get_amblight_data(data, &(data->raw.ali), node->content);
        else if (node->type == ELID_C)
            get_camera_data(data, &(data->raw.c), node->content);
        else if (node->type == ELID_L)
            get_light_data(data, &(data->raw.l), node->content);
        else
        {
            els[i] = build_element_node(data, node->content, node->type);
            (els[i])->type = node->type;
            i++;
        }
        node = node->next;
    }
    return ;
}

static void check_unique_elements(t_data *data, t_line **head)
{
    int count_ali;
    int count_c;
    int count_l;
    t_line *current;

    count_ali = 0;
    count_c = 0;
    count_l = 0;
    current = *head;
    while (current != NULL)
    {
        if (current->type == ELID_A)
            count_ali++;
        if (current->type == ELID_C)
            count_c++;
        if (current->type == ELID_L)
            count_l++;
        current = current->next;
    }
    if (count_ali != 1 || count_c != 1 || count_l != 1)
        ft_exit(data, ERRORS010);
}

void parse(t_data *data, char *filepath)
{
    int fd;
    char *s;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
    {
        data->emf = data->emf | EMF_PERROR;
        ft_exit(data, ERRORS006);
    }
    while(1)
    {
        s = ft_gnl(fd);
        if (s == NULL)
            break;
        process_line(data, s);
    }
    check_unique_elements(data, &(data->raw.lines));
    alloc_els(data);
    store_file_data(data);
    print_raw_element_list(data->raw.els);
    close(fd);
    return ;
}
