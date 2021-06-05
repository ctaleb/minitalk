/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 11:29:24 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/05 16:29:44 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*ft_chrjoin(char const *s1, char const c)
{
	int		size;
	char	*str;

	if (!s1 || !c)
		return (NULL);
	size = ft_strlen((char *)s1) + 2;
	str = ft_calloc(size, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcat(str, s1, size);
	str[size - 2] = c;
	return (str);
}

void	display(char **str)
{
	int	buf;

	if (*str)
		buf = ft_strlen(*str);
	else
		buf = 0;
	write(1, *str, buf);
	write(1, "\n", 1);
	free(*str);
	*str = NULL;
}

void	msg_build(char **str, char c)
{
	char	*tmp;

	if (!*str)
	{
		*str = ft_calloc(2, sizeof(char));
		*(str[0]) = c;
	}
	else
	{
		tmp = ft_chrjoin(*str, c);
		free(*str);
		*str = tmp;
	}
}
