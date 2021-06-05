/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:20:30 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/05 16:04:37 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

void			sig_reciever(int sig);
void			sig_sender(int pid, char *str);

		//parsing
int				parser(char *str);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);

		//utils
size_t			ft_strlen(const char *str);
int				power(int base, int power);
unsigned int	ft_nbrlen(long nb);
void			*ft_calloc(size_t count, size_t size);

#endif