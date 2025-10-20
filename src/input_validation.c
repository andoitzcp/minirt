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
