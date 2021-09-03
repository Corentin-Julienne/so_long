# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/20 17:28:24 by cjulienn          #+#    #+#              #
#    Updated: 2021/09/02 19:34:54 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = ./srcs/so_long.c \
	   ./srcs/check_map_validity_1.c \
	   ./srcs/check_map_validity_2.c

OBJS = $(SRCS:.c=.o)

INCLUDE_PATH = ./includes/
LIBFT_LIB = libft.a

LIBFT_PATH = ./libft/

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_PATH)

RM = rm -f

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	cp ./libft/libft.a .
	$(CC) $(CFLAGS) $(OBJS) -L. -lft -o $(NAME)
	@echo so_long successfully made !!!

all: 
	$(NAME)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)
	
fclean:	clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)
	$(RM) libft.a

re:	fclean all

.PHONY: all clean fclean re
