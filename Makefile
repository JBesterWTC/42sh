# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbester <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/28 12:09:30 by jbester           #+#    #+#              #
#    Updated: 2016/09/01 08:17:57 by jbester          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh

NAME2 = libft/libft.a

SRCS = main.c env.c function.c	\
	   command.c env2.c exec.c	\
	   echo.c echo_wait.c \

DIR = "libft"

FLAGS = -Wall -Werror -Wextra -ltermcap

$(NAME):
		@echo "Compiling 42sh..."
		@make -C $(DIR)
		@gcc -o $(NAME) $(SRCS) $(NAME2) $(FLAGS)
		@echo "42sh compiled."

all: $(NAME)

clean:
		@make clean -C $(DIR)

fclean:
		@make fclean -C $(DIR)
		@rm -f 42sh
		@echo "42sh cleaned."

re: fclean all
