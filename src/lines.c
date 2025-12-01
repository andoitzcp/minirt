/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 lines.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: iubieta- <iubieta@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/11/21 20:48:41 by iubieta-		   #+#	  #+#			  */
/*	 Updated: 2025/11/21 20:48:41 by iubieta-		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "minirt.h"

char	***split_line(char *s)
{
	size_t	len;
	size_t	i;
	void	***line;
	char	*aux;

	len = ft_strlen(s);
	if (s[len - 1] == '\n')
		s[len - 1] = '\0';
	line = (void ***)ft_split(s, ' ');
	i = 0;
	while (line && (char *)line[i] != NULL)
	{
		aux = (char *)line[i];
		line[i] = (void **)ft_split((char *)line[i], ',');
		free(aux);
		aux = NULL;
		i++;
	}
	return ((char ***)line);
}

t_line	*build_line_node(t_data *data, char ***line, int type)
{
	t_line	*node;

	node = ft_calloc(1, sizeof(t_line));
	if (node == NULL || line == NULL)
	{
		free_3parray(line);
		ft_exit(data, MALLOC_ERROR, 1);
	}
	node->type = type;
	node->content = line;
	node->next = NULL;
	return (node);
}

void	append_line_node(t_line **head, t_line *node)
{
	t_line	*current;

	current = *head;
	if (current == NULL)
	{
		*head = node;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = node;
	return ;
}

void	process_line(t_data *data, char *s)
{
	int		i;
	char	***line;
	t_line	*node;

	data->emf = data->emf | EMF_RAWLINES;
	i = 0;
	while (data->raw.re_el_types[i] != NULL)
	{
		if (match(data->raw.re_el_types[i++], s) == 0)
			continue ;
		if (i - 1 != ELID_BLANK_LINE)
		{
			line = split_line(s);
			node = build_line_node(data, line, i - 1);
			append_line_node(&(data->raw.lines), node);
		}
		return ;
	}
	free(s);
	s = NULL;
	destroy_regex(data);
	ft_exit(data, ERRORS007, 0);
	return ;
}
