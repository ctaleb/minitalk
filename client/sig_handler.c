/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 13:14:42 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/05 18:20:22 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	sig_reciever(int sig)
{
	if (sig == SIGUSR2)
	{
		write(1, "Server: Message recieved.\n", 26);
		exit(0);
	}
}

void	sig_sender(int pid, char *str)
{
	int		i;
	int		j;
	int		max;

	i = -1;
	max = ft_strlen(str);
	while (i++ < max)
	{
		j = 0;
		while (j < 8)
		{
			if (str[i] & 128 / power(2, j))
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(2);
			}
			else
				if (kill(pid, SIGUSR1) == -1)
					exit(2);
			j++;
			usleep(100);
		}
	}
}
