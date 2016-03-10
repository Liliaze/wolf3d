# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboudy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 10:53:12 by dboudy            #+#    #+#              #
#    Updated: 2016/03/10 16:32:40 by dboudy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
GCC = gcc
PATH_SRC = ./srcs/
PATH_OBJ = ./obj/
PATH_INC = libft/includes/
CFLAGS = -O3 -Weverything -Wall -Werror -Wextra
FLAGS2 = -lmlx -framework OpenGL -framework AppKit
HEADERS = ./includes/
SRC = main.c tools.c loop.c read_map.c menu.c\
	  init_data.c\
OBJS = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

all: $(NAME)

%.o: %.c $(HEADERS)/wolf3d.h
	gcc $(CFLAGS) -I $(HEADERS) -I $(PATH_INC) -c -o $@ $<

$(NAME): $(OBJS)
	make -C libft
	$(GCC) -o $(NAME) $(OBJS) -lm -L libft/ -lft $(FLAGS2)

.PHONY: clean fclean re

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
