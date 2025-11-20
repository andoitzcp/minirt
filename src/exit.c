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
int	ft_exit(t_data *data, char *s)
{
	uint8_t	emf;

	emf = data->emf;
	if ((emf & EMF_RAWL) == EMF_RAWL)
		free_lines(&(data->raw.lines));
	if ((emf & EMF_ELS) == EMF_ELS)
		free_els(data->raw.els);
	ft_putstr_fd(ERRORS000, STDERR_FILENO);
	if ((emf & EMF_PERROR) == EMF_PERROR)
		perror(s);
	else
		ft_putstr_fd(s, STDERR_FILENO);
	exit(errno);
}
