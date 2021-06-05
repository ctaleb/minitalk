# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/05 17:45:35 by ctaleb            #+#    #+#              #
#    Updated: 2021/06/05 17:56:32 by ctaleb           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

INCS = client.h

SRCS = main.c \
		sig_handler.c \
		parsing.c \
		utils.c

OBJS = $(SRCS:.c=.o)

NAME = client

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