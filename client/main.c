/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:13:11 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/05 17:32:12 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int ac, char *av[])
{
	int		pid;
	int		o_pid;
	char	*s_pid;

	signal(SIGUSR2, sig_reciever);
	if (ac != 3)
		exit (1);
	pid = parser(av[1]);
	sig_sender(pid, av[2]);
	o_pid = getpid();
	s_pid = ft_itoa(o_pid);
	sig_sender(pid, s_pid);
	free(s_pid);
	while (1)
		;
	return (0);
}
