/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 re_destroy.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: iubieta- <iubieta@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/11/30 23:21:30 by iubieta-		   #+#	  #+#			  */
/*	 Updated: 2025/11/30 23:21:31 by iubieta-		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libregex.h"

void	re_destroy(t_re **re)
{
	t_re	*node;
	t_re	*p;

	node = *re;
	while (node)
	{
		p = node;
		node = node->next;
		free(p);
		p = NULL;
	}
	free(re);
	re = NULL;
	return ;
}
