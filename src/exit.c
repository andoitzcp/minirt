/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 exit.c												:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: iubieta- <iubieta@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/11/20 20:26:45 by iubieta-		   #+#	  #+#			  */
/*	 Updated: 2025/11/20 20:26:45 by iubieta-		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "minirt.h"

void	free_lines(t_line **head)
{
	t_line	*current;
	t_line	*tmp;

	current = *head;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp->content);
		free(tmp);
	}
	return ;
}

void	free_els(t_elements **array)
{
	free(array);
	return ;
}

// Function used to handle errors and free memory
int	ft_exit(t_data *data, char *s, int type)
{
	uint8_t	emf;

	if (type == -1)
		ft_putstr_fd(s, STDOUT_FILENO);
	else
		printf("Error!\n");
	emf = data->emf;
	if ((emf & EMF_REGEX) == EMF_REGEX)
		destroy_regex(data);
	if ((emf & EMF_RAWLINES) == EMF_RAWLINES)
		destroy_rawlines(data->raw.lines);
	if ((emf & EMF_ELEMENTS) == EMF_ELEMENTS)
		destroy_elements(&data->raw);
	if ((emf & EMF_OBJECTS) == EMF_OBJECTS)
		destroy_objs(data->world.objs);
	if ((emf & EMF_CANVAS) == EMF_CANVAS)
		destroy_canvas(data->canvas);
	if (type == -1)
		exit(0);
	else if (type == 0)
		ft_putstr_fd(s, STDERR_FILENO);
	else
		ft_putstr_fd(s, STDERR_FILENO);
	exit(type);
}
