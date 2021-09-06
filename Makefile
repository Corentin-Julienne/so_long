# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/20 17:28:24 by cjulienn          #+#    #+#              #
#    Updated: 2021/09/05 18:57:10 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long

SRCS= ./srcs/so_long.c \
	  ./srcs/check_map_validity_1.c \
	  ./srcs/check_map_validity_2.c \
	  ./srcs/parse_map.c \
	  ./srcs/init_game.c

OBJS = $(SRCS:.c=.o)

INCLUDE_PATH = ./includes/

LIBFT_LIB = libft.a
LIBFT_PATH = ./libft/

MINILIBX_PATH= ./mlx/
MINILIBX_LIB= libmlx.dylib

CC= gcc
CFLAGS= -Wall -Wextra -Werror -I$(INCLUDE_PATH) -I$(MINILIBX_PATH)

RM= rm -f

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(MAKE) -C $(MINILIBX_PATH)
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	cp ./mlx/libmlx.dylib .
	@echo $(NAME) successfully made !!!

all: 
	$(NAME)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MINILIBX_PATH) clean
	$(RM) $(OBJS)
	
fclean:	clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)
	$(RM) $(MINILIBX_LIB)

re:	fclean all

.PHONY: all clean fclean re
