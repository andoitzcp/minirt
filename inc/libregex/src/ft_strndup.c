/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:02:06 by acampo-p          #+#    #+#             */
/*   Updated: 2022/12/10 10:28:23 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libregex_priv.h"

/*
** Takes a null terminated string 's' and a size 'n'.
** returns a heap allocated null terminated string of size 'n'. If original
** string is smaller than n it returns original string.
*/
char	*ft_strndup(const char *s, size_t n)
{
	char	*scpy;

	if (ft_strlen(s) < n)
		return (ft_strdup(s));
	scpy = (char *)malloc(sizeof(char) *(n + 1));
	if (!scpy)
		return (NULL);
	scpy = ft_memcpy(scpy, s, n);
	scpy[n] = '\0';
	return (scpy);
}
