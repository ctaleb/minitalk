/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 11:33:25 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/05 14:50:04 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	power(int base, int power)
{
	int	result;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	result = 1;
	while (power > 0)
	{
		result *= base;
		power--;
	}
	return (result);
}

size_t	ft_strlen(const char *str)
{
	size_t	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

void	ft_bzero(void *ptr, size_t size)
{
	unsigned int	i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)ptr;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	str = malloc(size * count);
	if (!str)
		return (NULL);
	ft_bzero(str, (size * count));
	return (str);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	src_len;
	unsigned int	dst_len;

	dst_len = ft_strlen(dst);
	i = dst_len;
	src_len = ft_strlen((char *)src);
	if (dst_size == 0 || dst_size - 1 < dst_len)
		return (dst_size + src_len);
	j = 0;
	while (src[j] && ((dst_size - dst_len - j - 1) > 0))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}
