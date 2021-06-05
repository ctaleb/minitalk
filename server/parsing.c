/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:36:03 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/05 17:20:08 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	symbol_set(char symbol)
{
	if (symbol == '-')
		return (-1);
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	unsigned long long	nb;
	int					i;
	int					sym;

	i = 0;
	sym = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		sym = symbol_set(str[i++]);
	nb = 0;
	while (ft_isdigit(str[i]))
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	if ((sym > 0 && nb > 2147483647) || (sym < 0))
		exit(5);
	return (nb * sym);
}

int	parser(char *str)
{
	int	i;
	int	pid;

	i = 0;
	pid = ft_atoi(str);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			exit(4);
		i++;
	}
	return (pid);
}
