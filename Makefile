# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asabri <asabri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 13:32:44 by asabri            #+#    #+#              #
#    Updated: 2023/03/16 09:37:59 by asabri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror 
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
SRC	= ft_atoi.c ft_split.c ft_substr.c get_next_line.c get_next_line_utils.c ft_read_map.c ft_wdcounter.c

OBJS = ${SRC:.c=.o}

all : $(NAME)

fdf : ${OBJS} fdf.o
	${CC} ${CFLAGS} ${MLXFLAGS} -o fdf ${OBJS} fdf.o 

%.o : %.c fdf.h
	${CC} ${CFLAGS} -o $@ -c $< 
clean:
	rm -f ${OBJS} fdf.o

fclean:	clean
	rm -f $(NAME)

re: fclean all
