/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 03:18:11 by asabri            #+#    #+#             */
/*   Updated: 2023/03/17 08:32:43 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int get_height(char const *map)
{
    int fd;
    char *line;
    int height;
    
    fd = open(map, O_RDONLY, 0);
    if (fd == -1)
        return (perror("err"), -1);
    height = 0;
    line = get_next_line(fd);
    while (line)
    {
        height++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (height);
}

int get_widht(char const *map)
{
    int width;
    int fd;
    char *line;
    
    fd = open(map, O_RDONLY, 0);
    line = get_next_line(fd);
    //printf("%s\n",line);
    width = ft_wdcounter(line, ' ');
    free(line);
    close(fd);
    return (width);   
}
void    fill_mtrx(int *z_line, char *line)
{
    char **z;
    int i;

    z = ft_split(line, ' ');
    i = 0;
    while (z[i])
    {
        z_line[i] = ft_atoi(z[i]);
        free(z[i]);
        i++;
    }
    free(z);
}

void    ft_read_map(char const *map,t_fdf *data)
{
    int fd;
    char *line;
    int i;
    
    data->height = get_height(map);
    data->width = get_widht(map);
    data->z = (int **)malloc(sizeof(int*) * (data->height + 1));
    i = 0;
    while (i <= data->height)
        data->z[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
    fd = open(map, O_RDONLY, 0);
    i = 0;
    line = get_next_line(fd);
    while (line)
    {
        fill_mtrx(data->z[i],line);
        i++;
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    data->z[i] = NULL;
    
}