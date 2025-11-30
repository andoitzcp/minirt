/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 libregex.h											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: iubieta- <iubieta@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/11/30 23:19:24 by iubieta-		   #+#	  #+#			  */
/*	 Updated: 2025/11/30 23:19:24 by iubieta-		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#ifndef LIBREGEX_H
# define LIBREGEX_H

# include <stdlib.h>
# include <stdint.h>
# include <stddef.h>
# include <stdio.h>

/* Struture definitions */

typedef enum e_type
{
	T_NOTSET,
	T_CHAR,
	T_CHARSET,
	T_BEGIN = '^',
	T_END = '$',
	T_DOT = '.',
	T_STAR = '*',
	T_INTER = '?',
	T_PLUS = '+',
	T_NOTVALID
}	t_type;

typedef struct s_re
{
	int8_t		type;
	char		c;
	uint8_t		cs[128];
	ssize_t		minc;
	ssize_t		maxc;
	size_t		rawlen;
	struct s_re	*next;
}				t_re;

/* Function prototypes */
int		match(t_re **head, char *str);
t_re	**re_new(char *s);
void	re_destroy(t_re **re);

#endif // LIBREGEX_H_
