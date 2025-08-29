#include "minirt.h"

void get_raw_content(t_data *data, char *filepath)
{
    int fd;
    char *s;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
    {
        //perror(ERRORS000);
        //exit(1);
        data->emf = data->emf | EMF_PERROR;
        ft_exit(data, ERRORS006);
    }
    while(1)
    {
        s = ft_gnl(fd);
        if (s == NULL)
            break;
        append_rawline_node(data, s);
    }
    close(fd);
    return ;
}

void parse(t_data *data, char *filepath)
{
    t_rawlines *rawl;

    rawl = NULL;
    data->rawl = &rawl;
    if (!is_valid_input_file(filepath))
        ft_exit(data, ERRORS005);
    get_raw_content(data, filepath);
    print_ds_rawl(data->rawl);
    classify_raw_content_into_elements(data->rawl);
    print_ds_rawl(data->rawl);
    if (has_raw_content_invalid_lines(data->rawl))
        ft_exit(data, ERRORS006);
    trim_raw_content_ws_nodes(data->rawl);
    print_ds_rawl(data->rawl);
    breakdown_rawlines(data->rawl);
    //is_valid_data()
}
