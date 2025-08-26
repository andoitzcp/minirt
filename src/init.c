#include "minirt.h"


void init_element_node(t_elements *el)
{
}

void init_element_array(t_data *data)
{
    uint i;
    t_elements *els;
    t_rawlines *rawl;

    i = 0;
    els = data->els;
    rawl = *(data->rawl);
    if (data->nels != get_element_qty(data->rawl))
        ft_exit(data, ERRORS004);
    data->els = ft_calloc(data->nels, sizeof(t_elements));
    if (data->els == NULL)
        ft_exit(data, ERRORS003);
    while (i < data->nels)
        init_element_node(&(data->els[i++]));


}

void init(t_data *data, char *filepath)
{
    t_rawlines *rawl;

    rawl = NULL;
    data->rawl = &rawl;
    get_raw_content(data, filepath);
    classify_raw_content_into_elements(data->rawl);
    trim_raw_content_ws_nodes(data->rawl);
    if (has_raw_content_invalid_lines(data->rawl) != 0)
        ft_exit(data, ERRORS002);
    data->nels = get_element_qty(data->rawl);
}
