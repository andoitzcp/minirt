/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:46:14 by acampo-p          #+#    #+#             */
/*   Updated: 2022/12/13 18:57:24 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	len;

	len = 0;
	if (s)
	{
		len += ft_putstr_fd(s, fd);
		len += ft_putchar_fd('\n', fd);
	}
	return (len);
}
