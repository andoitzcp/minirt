#include "minirt.h"
#include <unistd.h>

void free_rawl(t_rawlines **head)
{
    t_rawlines *current;
    t_rawlines *tmp;

    current = *head;
    while (current != NULL)
    {
        tmp = current;
        current = current->next;
        free(tmp->line);
        free(tmp);
    }
    return ;
}

void free_els(t_elements *array)
{
    free(array);
    return ;
}

// Function used to handle errors and free memory
int ft_exit(t_data *data, char *s)
{
    uint8_t emf;

    emf = data->emf;
    if ((emf & EMF_RAWL) == EMF_RAWL)
        free_rawl(data->rawl);
    if ((emf & EMF_RAWL) == EMF_RAWL)
        free_els(data->els);
    ft_putstr_fd(ERRORS000, STDERR_FILENO);
    if (errno == 0)
        ft_putstr_fd(s, STDERR_FILENO);
    else
        perror(s);
    exit(errno);
}
