/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 02:50:11 by asabri            #+#    #+#             */
/*   Updated: 2023/05/12 04:53:10 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "get_next_line.h"

typedef struct s_map
{
    int **x; //x[i] == element wich i means pos x, x[i][0] = z, x[i][1] = color so every x[i] has 2 elements;
    t_map *next;
}t_map;

#endif