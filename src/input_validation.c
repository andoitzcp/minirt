#include "minirt.h"

/*
** Function that checks if the input file passed from the command line args is a
** valid file. Used to verify we receive a valid filepath with a '.rt' extesion
*/
int8_t is_valid_input_file(char *filepath)
{
    size_t file_name_len;
    size_t ext_len;
    char *file_name_ext;

    file_name_len = ft_strlen(filepath);
    ext_len = ft_strlen(RT_FILE_EXTENSION);
    file_name_ext = filepath + file_name_len - ext_len;
    if (file_name_len > MAX_PATH_LENGTH)
        return (FALSE);
    if (ft_strncmp(file_name_ext, RT_FILE_EXTENSION, ext_len) != 0)
        return (FALSE);
    while (*filepath != '\0')
    {
        if (ft_isascii(*filepath) == 0)
            return (FALSE);
        filepath++;
    }
    return (TRUE);
}

int8_t has_valid_charset(char *s, char *set)
{
    size_t i;

    i = 0;
    while (s[i] != '\0')
    {
        if (ft_strchr(set, s[i]) == NULL)
            return (FALSE);
        i++;
    }
    return (TRUE);
}

t_intarray get_char_separated_array_of_ints(char *s, char c)
{
    size_t i;
    t_intarray ints;

    ints.array = NULL;
    ints.len = 0;
    if (*s == '\0')
        return (ints);
    i = 0;
    while (TRUE)
    {

        if

    }

}

int8_t is_valid_rgb_str(char *s)
{
    int8_t i;
    char *tmp;
    t_intarray ints[3];

    if (*tmp == '\0')
        return (FALSE);
    if (ft_strlen(tmp) > MAX_RGB_STR_LEN)
        return (FALSE);
    if (has_valid_charset(tmp, RGB_STR_VALID_CHARSET) == FALSE)
        return (FALSE);
    i = 0;
    while (i < RGB_STR_ELEMENTS)
    {
        if (ft_isdigit(*tmp) == FALSE)
            return (FALSE);
        tmp = ft_strchr(tmp, ',');
        if (tmp == NULL && i < RGB_STR_ELEMENTS - 1)
            return (FALSE);
        else
            tmp++;
    }
}

int8_t is_valid_data(t_data *data)
{
    (void)data;
    return (1);
}
