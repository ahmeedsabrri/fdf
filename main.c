/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 03:02:14 by asabri            #+#    #+#             */
/*   Updated: 2023/05/15 04:32:40 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int main(int ac, char **av)
{
    t_map *map;
    //t_point p; 
    t_data *data;
    map = NULL;
    data = NULL;
    if (ac == 2)
    {
        map = parsing(av[1]);
        data->mlx = mlx_init();
        data->win = mlx_new_window(data->mlx,800,600,"FDF");
        data->img = mlx_new_image(data->mlx,800,600);
        draw(map,data);
        mlx_loop(data->mlx);
    
    }
    ft_malloc(0,2);
    // int i;
    // int j;

    // i = 0;
    // j = 0;
    // while(map)
    // {
    //     i = 0;
    //     int **tab = map->x;
    //     while(tab[i])
    //     {
    //         printf("[z=%d,c=%d]", tab[i][0], tab[i][1]);
    //         i++;
    //     }
    //     puts("\n");
    //     map = map->next;
    //     //printf("%p\n", data);
    // }
    return 0;
}
