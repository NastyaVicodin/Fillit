#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alukyane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 22:31:54 by alukyane          #+#    #+#              #
#    Updated: 2017/11/29 18:46:04 by alukyane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
SOURCE =	main.c \
			ft_read_from_file.c \
			ft_strdup_read.c \
			ft_is_valid_str.c \
			ft_is_val_figures.c \
			ft_str_chr_cpy.c \
			ft_make_arr_tetrs.c \
			ft_feel.c \
			ft_fill.c \
			new_algo.c \
			ft_additional.c \
			ft_bzero.c \
			ft_memalloc.c \
			ft_strncat.c \
			ft_strcpy.c \
			ft_strsplit.c \
			ft_putchar.c \
            ft_putstr.c \
            ft_strsub.c \
            ft_strlen.c
OBJS = $(SOURCE:.c=.o)
all: $(NAME)

%.o:%.c
	gcc -o $@ -c $<

$(NAME): $(OBJS)
	gcc -Wall -Wextra -Werror $(SOURCE) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
