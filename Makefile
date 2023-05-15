# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asabri <asabri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 04:45:23 by asabri            #+#    #+#              #
#    Updated: 2023/05/15 04:35:57 by asabri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = get_next_line.c parsing.c main.c map_utis.c libftmalloc/ft_malloc.c libftmalloc/utils_malloc.c \
	utils.c draw.c

CC = cc
FLAGS = -Wall -Wextra -Werror 
RM = rm -rf
HEADER = fdf.h   

OBJS = $(SRC:.c=.o)
OBJSB = $(SRCB:.c=.o)

all : $(NAME)

libftrule :
	make -C libft_42

%.o : %.c $(HEADER_M) libft_42/libft.h
		$(CC) $(FLAGS) -Imlx -o $@ -c $<

$(NAME) : $(OBJS) $(HEADER_M) libftrule
		$(CC) $(FLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit libft_42/libft.a -o $@ 
 
clean :
	$(RM) $(OBJS) 
	make clean -C libft_42

fclean : clean
	$(RM) $(NAME) 
	make fclean -C libft_42
	
re : fclean all