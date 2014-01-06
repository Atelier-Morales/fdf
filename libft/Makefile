# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmorales <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/13 14:09:07 by fmorales          #+#    #+#              #
#    Updated: 2013/12/22 15:53:38 by fmorales         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c \
	  ft_strcmp.c \
	  ft_strlen.c \
	  ft_strsplit.c \
	  ft_strsub.c 

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I .

RM = /bin/rm -f

all: $(NAME)

%.o: %.c
	@ gcc -c -o $@ $^ $(CFLAGS)

$(NAME): $(OBJ)
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $(NAME)

clean:
	@ $(RM) $(OBJ)

fclean: clean
	@ $(RM) $(NAME)

re: fclean all
