# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/04 13:14:51 by ctaleb            #+#    #+#              #
#    Updated: 2021/06/05 18:27:38 by ctaleb           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

S_PATH = server/

C_PATH = client/

all: server_ client_

server_:
	make -C $(S_PATH)

client_:
	make -C $(C_PATH)

bonus: all

clean:
	make -C $(S_PATH) clean
	make -C $(C_PATH) clean

fclean:
	make -C $(S_PATH) fclean
	make -C $(C_PATH) fclean

re: fclean all 