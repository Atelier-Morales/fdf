# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmorales <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/12 18:18:25 by fmorales          #+#    #+#              #
#    Updated: 2013/12/24 10:00:06 by fmorales         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MKEX = cc -o
SRC = 	fdf.c			  \
	  	ft_draw.c		  \
		duplicate_lists.c \
		get_coord.c		  \
		key_hook.c		  \
		put_pixel.c		  \
		main.c			  \
	  	getnextline.c 
FLAGS = -Wall -Wextra -Werror
OBJECT = $(SRC:.c=.o)
COMP = cc -c
NAME = fdf

all : $(NAME)

$(NAME) : $(OBJECT)
		@$(MKEX) $(NAME) $(OBJECT) -L /usr/X11/lib -lmlx -lXext -lX11 -L libft/ -lft
		@echo "FDF : vous pouvez utliser les touches a-w-s-d et les fleches haut et bas"

$(OBJECT) :
		@make -C libft/
		@$(COMP) $(SRC) $(FLAGS) -I./ -I /usr/X11/include/ -I libft/
		@echo "Compilation of C files succesful"

clean :
		@/bin/rm -f $(OBJECT)
		@echo "Object deleted"


fclean : clean
		@/bin/rm -f $(NAME)
		@echo "Folder cleanup successful"

re : fclean all
