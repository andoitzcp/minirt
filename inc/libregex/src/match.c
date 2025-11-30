/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 match.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: iubieta- <iubieta@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/11/30 23:20:36 by iubieta-		   #+#	  #+#			  */
/*	 Updated: 2025/11/30 23:20:36 by iubieta-		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libregex.h"

static int	is_charmatch(t_re *node, char *str);
static int	matchstar(t_re *re1, t_re *re2, char *str);
static int	matchcount(t_re *re1, t_re *re2, char *str);
static int	matchhere(t_re *re, char *str);

static int	is_charmatch(t_re *node, char *str)
{
	if (node->type == T_CHAR)
		return (node->c == *str);
	else if (node->type == T_CHARSET)
		return (node->cs[(int)*str]);
	else if (node->type == T_DOT)
		return (1);
	else
		return (-1);
	return (0);
}

static int	matchstar(t_re *re1, t_re *re2, char *str)
{
	while (1)
	{
		if (matchhere(re2, str))
			return (1);
		if (*str == '\0')
			break ;
		if (is_charmatch(re1, str) == 0)
			break ;
		str++;
	}
	return (0);
}

static int	matchcount(t_re *re1, t_re *re2, char *str)
{
	ssize_t	i;

	i = 0;
	while (1)
	{
		if (re1->maxc != -1 && i > re1->maxc)
			return (0);
		if (i >= re1->minc)
		{
			if (matchhere(re2, str))
				return (1);
		}
		if (*str == '\0')
			break ;
		if (is_charmatch(re1, str) == 0)
			break ;
		str++;
		i++;
	}
	return (0);
}

static int	matchhere(t_re *re, char *str)
{
	if (re == NULL)
		return (1);
	else if (re->next != NULL)
	{
		if (re->next->type == T_STAR)
			return (matchstar(re, re->next->next, str));
	}
	if (re->type == T_END)
		return (*str == '\0');
	if (re->minc != -1)
		return (matchcount(re, re->next, str));
	if (*str != '\0' && (is_charmatch(re, str) == 1))
		return (matchhere(re->next, str + 1));
	return (0);
}

int	match(t_re **head, char *str)
{
	t_re	*re;

	re = *head;
	if (re == NULL)
		return (1);
	if (re->type == T_BEGIN)
		return (matchhere(re->next, str));
	while (1)
	{
		if (matchhere(re, str))
			return (1);
		if (*str == '\0')
			break ;
		str++;
	}
	return (0);
}
