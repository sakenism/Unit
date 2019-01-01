#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 18:14:20 by myuliia           #+#    #+#              #
#    Updated: 2018/11/26 14:35:33 by myuliia          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC = ./helper.c\
	  ./ft_error.c\
	  ./ft_bzero.c\
	  ./ft_memset.c\
	  ./ft_putchar.c\
	  ./ft_sqrt.c\
	  ./ft_strcat.c\
	  ./ft_strlen.c\
	  ./ft_strncpy.c\
	  ./ft_strndup.c\
	  ./ft_strsplit.c\
	  ./fill.c\
	  ./ft_check_block.c\
	  ./fresh.c\

OBJ = $(SRC:.c=.o)

HEADER = fillit.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	gcc -c -o $@ $<

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all