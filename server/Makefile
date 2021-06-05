# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/04 13:14:49 by ctaleb            #+#    #+#              #
#    Updated: 2021/06/05 17:58:08 by ctaleb           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

INCS = server.h

SRCS = main.c \
		sig_handler.c \
		displayer.c \
		parsing.c \
		display_utils.c \
		utils.c

OBJS = $(SRCS:.c=.o)

NAME = server

.PHONY = all $(NAME) clean fclean re

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -I . -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I . -o $@ $(OBJS)

bonus: all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all