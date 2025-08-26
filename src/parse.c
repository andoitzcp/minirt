#include "minirt.h"

void get_raw_content(t_data *data, char *filepath)
{
    int fd;
    char *s;

    fd = open(filepath, O_RDONLY);
    while(1)
    {
        s = ft_gnl(fd);
        if (s == NULL)
            break;
        append_rawline_node(data, s);
    }
    return ;
}

void parse(t_data *data, char *filepath)
{
    int8_t i;

    i = is_valid_input_file(filepath);
    ft_putnbr_fd(i, 1);
    get_raw_content(data, filepath);
    //is_valid_data()

}
