/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 23:19:15 by iubieta-          #+#    #+#             */
/*   Updated: 2025/11/30 23:37:33 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libregex_priv.h"

void	get_node_type(t_re *node, char *s)
{
	if (ft_strchr(".*?+", *s) != NULL)
	{
		node->type = (int8_t) * s;
		node->rawlen = 1;
	}
	else if (*s == '\\')
		node->type = T_CHAR;
	else if (*s == '[')
	{
		node->type = T_CHARSET;
	}
	else if (ft_isascii(*s))
		node->type = T_CHAR;
	else
		node->type = T_NOTVALID;
}

void	get_node_c(t_re *node, char *s)
{
	if (node->type != T_CHAR)
		return ;
	node->rawlen = 1;
	if (*s == '\\')
	{
		if (s[1] == '\0')
			return ;
		node->rawlen = 2;
		node->c = s[1];
	}
	else
		node->c = *s;
	return ;
}

uint8_t	get_node_cs(t_re *node, char *s)
{
	char	*t;
	int		neg;

	if (node->type != T_CHARSET)
		return (0);
	t = ft_chrstrchr(s, '[', ']', '\\');
	neg = (*t == '^');
	node->rawlen = ft_strlen(t) + 2;
	if (get_charset(node->cs, t + neg) != 0)
		return (free(t), 1);
	if (neg != 0)
		reverse_charset(node->cs);
	return (free(t), 0);
}

uint8_t	get_node_minc(t_re *node, char *s)
{
	char	*t;

	if (s[node->rawlen] != '{')
		return (0);
	if (node->type != T_CHAR && node->type != T_CHARSET)
		return (1);
	t = ft_chrstrchr(s + node->rawlen, '{', '}', '\\');
	node->rawlen += ft_strlen(t) + 2;
	if (get_reps(&(node->minc), t) != 0)
		return (free(t), 1);
	return (free(t), 0);
}

uint8_t	get_node_maxc(t_re *node, char *s)
{
	char	*t;

	if (s[node->rawlen] != '{')
		return (0);
	if (node->type != T_CHAR && node->type != T_CHARSET)
		return (1);
	t = ft_chrstrchr(s + node->rawlen, '{', '}', '\\');
	node->rawlen += ft_strlen(t) + 2;
	if (get_reps(&(node->maxc), t) != 0)
		return (free(t), 1);
	return (free(t), 0);
}
