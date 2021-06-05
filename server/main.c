/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:01:57 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/05 14:47:16 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "#Server's PID: ", 15);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, sig_reciever);
	signal(SIGUSR2, sig_reciever);
	while (1)
		;
	return (0);
}
