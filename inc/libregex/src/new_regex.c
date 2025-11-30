/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 new_regex.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: iubieta- <iubieta@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/11/30 23:21:17 by iubieta-		   #+#	  #+#			  */
/*	 Updated: 2025/11/30 23:21:18 by iubieta-		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libregex.h"
#include "libregex_priv.h"

t_re	**re_new(char *s)
{
	t_re	**head;
	t_re	*node;
	size_t	i;

	head = malloc(sizeof(t_re *));
	if (!head)
		return (perror("Malloc error"), NULL);
	*head = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		node = build_re_node(s + i);
		if (node == NULL)
			return (perror("not a valid regex"), NULL);
		append_re_node(head, node);
		i += node->rawlen;
	}
	convert_delimiters(head);
	return (head);
}
