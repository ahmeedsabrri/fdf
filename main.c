/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 03:02:14 by asabri            #+#    #+#             */
/*   Updated: 2023/05/16 02:08:15 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int ac, char **av)
{
    t_map *map;
    t_point p; 
    t_data *data;
    
    map = NULL;
    
    p.x = 0;
    p.y = 0;
    p.z = 0;
    p.c = 0;
    int i;
    int j;

    i = 0;
    j = 0;
    data = ft_malloc(sizeof(t_data),1);
    if (!data)
        ft_malloc(0,0);
    
    // p.width = 0;
    // p.height = 0;
    if (ac == 2)
    {
        map = parsing(av[1],&p);
        // while(map)
        // {
        //     int **t = map->x;
        //     i = -1;
        //     while(t[++i])
        //     {
        //         printf("line = %d, z = %d \n", j, t[i][0]);
        //         // i++;
        //     }
        //     printf("----\n");
        //     j++;
        //     map = map->next;
        // }
        // printf("zab = %d", map.x[2][2]);
        data->nc = 0;
        data->nz = 0;
        data->xup = p.width;
        data->yup = p.height;
        data->zoom = 0;
        data->mlx = mlx_init();
        data->win = mlx_new_window(data->mlx,1500,1000,"FDF");
        draw(map,p,data);
        mlx_loop(data->mlx);
    
    }
    ft_malloc(0,2);
    return 0;
}
