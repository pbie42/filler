# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbie <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/15 11:55:43 by pbie              #+#    #+#              #
#    Updated: 2016/05/19 14:54:01 by pbie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pbie.filler

CFLAGS = -g -I includes

SRC = main.c \
		src/utils/enemy_setup.c \
		src/utils/free_play.c \
		src/utils/malloc_real.c \
		src/coordinates.c \
		src/diagonal.c \
		src/enemy.c \
		src/ft_strhas.c \
		src/parsing.c \
		src/path.c \
		src/piece.c \
		src/placing.c \
		src/straight.c \
		src/territory.c \


OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) -I libft/includes/libftprintf.h libft/libftprintf.a -ltermcap
	@echo "$(NAME) created"

clean :
	make -C libft clean
	rm -rf $(OBJ)
	@echo "OBJ deleted"

fclean : clean
	rm -rf $(NAME)
	rm -rf libft/libftprintf.a
	@echo "$(NAME) deleted"

re : fclean all

.PHONY: all clean fclean re
