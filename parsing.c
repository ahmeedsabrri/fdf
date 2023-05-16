/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 02:49:57 by asabri            #+#    #+#             */
/*   Updated: 2023/05/16 01:32:20 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int mtrlen(void **mtr)
{
  int len;
  len = -1;
  while(mtr[++len])
    ;
  return(len);
}

int *get_z(char *lwyen)
{
    char **coord;
    int *tab;
    
    coord = ft_split(lwyen, ',');
    tab = ft_malloc(2 * sizeof(int), 1);
    tab[0] = ft_atoi(coord[0]);
    tab[1] = 0xffffff;
    (coord[1]) && (tab[1] = hextodec(coord[1]));
    return(tab);
}

int **get_x(char *line,int *count)
{
    char **mtr;
    int **x;
    int i;
    *count = 0;
    
    mtr = ft_split(line, 32);
    x = ft_malloc((mtrlen((void **)mtr) + 1) * sizeof(int *), 1);
    i = -1;
    while(mtr[++i])
        x[i] = get_z(mtr[i]);
    x[i] = NULL;
    *count = i;
    return(x);
}

t_map *parsing(char *arg,t_point *p)
{
    int fd;
    int count;
    char *line;
    t_map *map;
    // t_point *point;

    map = NULL;
    p->height = 0;
    count = 0;
    fd = open(arg, O_RDONLY);
    if(fd < 0)
        return(NULL); //TODO : invalid file free with ur gc;
    line = get_next_line(fd);
    while(line)
    {
        ft_lstadd_back(&map, ft_lstnew(get_x(line,&count)));
        p->height++;
        free(line);
        line = get_next_line(fd);
    }
    p->width = count;
    return(map);
}