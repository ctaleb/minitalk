/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:20:18 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/05 16:02:10 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

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

char	*ft_itoa(int n)
{
	unsigned int	size;
	char			*nbr;
	long			nb;

	size = ft_nbrlen(n);
	nbr = ft_calloc(size + 1, sizeof(char));
	if (!nbr)
		return (NULL);
	nb = n;
	if (nb < 0)
	{
		nbr[0] = '-';
		nb *= -1;
	}
	size--;
	if (nb == 0)
		nbr[size] = 48;
	while (nb != 0)
	{
		nbr[size] = nb % 10 + 48;
		nb /= 10;
		size--;
	}
	return (nbr);
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
