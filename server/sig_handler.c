/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 10:24:47 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/05 17:26:17 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	mode_swap(int *mode)
{
	if (*mode)
		*mode = 0;
	else
		*mode = 1;
}

void	sig_sender(char **str)
{
	int	pid;

	pid = parser(*str);
	kill(pid, SIGUSR2);
	free(*str);
	*str = NULL;
}

void	sig_reciever(int sig)
{
	static int	mode;
	static int	i;
	static char	c;
	static char	*str;

	if (sig == SIGUSR2)
		c |= 128 / power(2, i);
	i++;
	if (i == 8)
	{
		i = 0;
		if (!c && !mode)
		{
			display(&str);
			mode_swap(&mode);
		}
		else if (!c && mode)
		{
			sig_sender(&str);
			mode_swap(&mode);
		}
		else
			msg_build(&str, c);
		c = 0;
	}
}
