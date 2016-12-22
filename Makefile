# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 13:42:55 by fel-mazo          #+#    #+#              #
#    Updated: 2016/12/22 12:18:59 by fel-mazo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
NAME	= gnl
CFLAGS	= -g -Wall -Wextra -Werror
SRC		= get_next_line.c main.c

OBJ		= $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) -L./libft -lft  -I . $(SRC) -o $(NAME)
clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)
