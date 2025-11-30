/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_node_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 23:21:39 by iubieta-          #+#    #+#             */
/*   Updated: 2025/11/30 23:31:18 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libregex_priv.h"

uint8_t	check_re_node(t_re *node)
{
	if (node->type == T_NOTVALID)
		return (1);
	return (node->minc > node->maxc && node->maxc != -1);
}

void	init_re_node(t_re *node)
{
	node->minc = -1;
	node->maxc = -1;
}

t_re	*build_re_node(char *s)
{
	t_re	*node;

	node = ft_calloc(sizeof(t_re), 1);
	if (!node)
		return (NULL);
	init_re_node(node);
	get_node_type(node, s);
	get_node_c(node, s);
	if (get_node_cs(node, s) != 0)
		return (free(node), NULL);
	if (get_node_minc(node, s) != 0)
		return (free(node), NULL);
	if (get_node_maxc(node, s) != 0)
		return (free(node), NULL);
	if (check_re_node(node) != 0)
		return (free(node), NULL);
	node->next = NULL;
	return (node);
}

void	append_re_node(t_re **head, t_re *node)
{
	t_re	*current;

	current = *head;
	if (current == NULL)
	{
		*head = node;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = node;
}
