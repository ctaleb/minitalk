/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:02:30 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/05 15:40:14 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

void		sig_reciever(int sig);
void		sig_sender(char **str);

		//display
void		ft_putnbr_fd(int n, int fd);
void		display(char **str);
void		msg_build(char **str, char c);

		//parsing
int			parser(char *str);

		//utils
char		*ft_chrjoin(char const *s1, char const c);
size_t		ft_strlcat(char *dst, const char *src, size_t dst_size);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_strlen(const char *str);
int			power(int base, int power);

#endif