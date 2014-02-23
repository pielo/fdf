# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/06 17:44:08 by mlanglet          #+#    #+#              #
#    Updated: 2013/12/21 16:23:34 by mlanglet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf.c \
	  ft_init.c \
	  ft_draw_line.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I. -I./libft/includes/

RM = /bin/rm -f

MAKE = make

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) libft/*.c -L/usr/X11/lib -lmlx -lXext -lX11

clean:
	$(MAKE) clean -C libft
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C libft
	$(RM) $(NAME)

re: fclean all
