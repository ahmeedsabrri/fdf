/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 02:50:11 by asabri            #+#    #+#             */
/*   Updated: 2023/05/12 22:45:20 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "libftmalloc/ft_malloc.h"
# include "get_next_line.h"
#include <stdio.h>

typedef struct s_map
{
    int **x; //x[i] == element wich i means pos x, x[i][0] = z, x[i][1] = color so every x[i] has 2 elements;
    struct s_map *next;
}t_map;

void	ft_lstadd_back(t_map **lst, t_map *new);
t_map	*ft_lstlast(t_map *lst);
t_map	*ft_lstnew(int **content);
int	ft_lstsize(t_map *list);
t_map *parsing(char *arg);
int **get_x(char *line);
int *get_z(char *lwyen);
int mtrlen(void **mtr);
#endif