# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 02:02:39 by imimouni          #+#    #+#              #
#    Updated: 2023/02/12 02:02:17 by imimouni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

NAME = fractol

CC = gcc

Header = fractol.h

SRC = event_handlers.c \
	  fractals.c \
	  main.c \
	  maps.c \
	  ft_putstr.c\

OBJS = $(SRC:.c=.o)

MLX = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)
	clear
	@echo "\033[0;92m Fractol is ready.\033[0m"

%.o: %.c $(Header)
	$(CC) $(CFLAGS) -c $<

f: all clean
	clear
	@echo "\033[0;92m Fractol is ready.\033[0m"

clean :
	@rm -f $(OBJS)
	clear
	@echo "\033[0;93m object files removed.\033[0m"

fclean : clean
	@rm -f $(NAME)
	clear
	@echo "\033[0;93mthe object files and the exicutable are removed.\033[0m"

re : fclean all

.PHONY	:	all clean fclean re f