# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asabri <asabri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 04:45:23 by asabri            #+#    #+#              #
#    Updated: 2023/05/12 22:51:15 by asabri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = get_next_line.c parsing.c main.c map_utis.c libftmalloc/ft_malloc.c libftmalloc/utils_malloc.c

CC = cc
FLAGS = -Wall -Wextra -Werror 
RM = rm -rf
HEADER = fdf.h   

OBJS = $(SRC:.c=.o)
OBJSB = $(SRCB:.c=.o)

all : $(NAME)

libft :
		make -C libft/libft

%.o : %.c $(HEADER_M) libft/libft.h
		$(CC) $(FLAGS) -o $@ -c $<

$(NAME) : $(OBJS) $(HEADER_M) libft
		$(CC) $(FLAGS) $(OBJS) libft/libft.a -o $@ 
 
clean :
	$(RM) $(OBJS) 
	make clean -C libft
fclean : clean
		$(RM) $(NAME) 
		make fclean -C libft
re : fclean all