/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 03:02:14 by asabri            #+#    #+#             */
/*   Updated: 2023/05/17 05:43:26 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int key_hooks(int key,t_data *data)
{
    t_point p;
    t_map *map;

    p.x = 0;
    p.y = 0;
    p.z = 0;
    p.c = 0;
    
    if (key == 116)
        data->nz += 1;
    else if (key == 121)
        data->nz -= 1;
    else if (key == 0)
		data->sx -= 50;
	else if (key == 1)
		data->sy += 50;
    else if (key == 13)
		data->sy -= 50;
	else if (key == 2)
		data->sx += 50;
    else if (key == 15)
    {
        data->rx = 45;
        data->ry = 45;
        data->rz = -35;
    }
    else if (key == 3)
    {
        data->rx = 0;
        data->ry = 0;
        data->rz = 0;
    }
    else if (key == 69)
        data->zoom += 1;
    else if (key == 78)
        data->zoom -= 1;
    else if (key == 126)
        data->rx += 1;
    else if (key == 125)
        data->rx -= 1;
    else if (key == 123)
        data->ry += 1;
    else if (key == 124)
        data->ry -= 1;
    else if (key == 117)
        data->rz += 1;
    else if (key == 115)
        data->rz -= 1;
    else if (key == 53)
        return (ft_malloc(0,2),0);
    mlx_destroy_image(data->mlx,data->img);
    map = parsing(data->fl,&p);
    data->img = mlx_new_image(data->mlx,1500,1000);
    data->addr = mlx_get_data_addr(data->img,&data->bits_per_pixel,&data->line_length,&data->endian);
    draw(map,p,data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}
int initialize(int key)
{
  printf("%d\n",key);
  return (key);      
}
void ff(void)
{
    system("leaks fdf");
}
int	ft_exit(void)
{
	exit(0);
}
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
    atexit(ff);
    data = ft_malloc(sizeof(t_data),1);
    if (!data)
        ft_malloc(0,0);
    if (ac == 2)
    {
        map = parsing(av[1],&p);
        data->nc = 0;
        data->nz = 0;
        data->xup = p.width;
        data->yup = p.height;
        data->zoom = 0;
        data->sy = 0;
        data->sx = 0;
        data->rx = 45;
        data->ry = 45;
        data->rz = -35;
        data->fl = av[1];
        data->mlx = mlx_init();
        data->win = mlx_new_window(data->mlx,1500,1000,"FDF");
        data->img = mlx_new_image(data->mlx,1500,1000);
        data->addr = mlx_get_data_addr(data->img,&data->bits_per_pixel,&data->line_length,&data->endian);
        draw(map,p,data);
        mlx_hook(data->win, 2, 1L<<0,key_hooks,data);
        mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
        mlx_key_hook(data->win,initialize,&data);
        mlx_hook(data->win, 17, 0, ft_exit, &data);
        mlx_loop(data->mlx);
    }
    ft_malloc(0,2);
    return 0;
}
