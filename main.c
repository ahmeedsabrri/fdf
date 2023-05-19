/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 03:02:14 by asabri            #+#    #+#             */
/*   Updated: 2023/05/19 04:57:06 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize(t_data *data, t_point *p, char *fn)
{
	p->x = 0;
	p->y = 0;
	p->z = 0;
	p->c = 0;
	p->mode = 0;
	data->nc = 0;
	data->nz = 1;
	data->xup = p->width;
	data->yup = p->height;
	data->zoom = 0;
	data->sy = 0;
	data->sx = 0;
	data->rx = 45;
	data->ry = 45;
	data->rz = -35;
	data->fl = fn;
}

t_data	*key_hooks2(int key, t_data *data)
{
	(key == 116) && (data->nz += 1);
	(key == 121) && (data->nz -= 1);
	(key == 0) && (data->sx -= 50);
	(key == 1) && (data->sy += 50);
	(key == 13) && (data->sy -= 50);
	(key == 2) && (data->sx += 50);
	(key == 126) && (data->rx += 1);
	(key == 125) && (data->rx -= 1);
	(key == 123) && (data->ry += 1);
	(key == 124) && (data->ry -= 1);
	(key == 117) && (data->rz += 1);
	(key == 115) && (data->rz -= 1);
	if (key == 15)
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
	return (data);
}

int	key_hooks(int key, t_data *data)
{
	t_point	p;

	p.x = 0;
	p.y = 0;
	p.z = 0;
	p.c = 0;
	p.mode = 0;
	(key == 69) && (data->zoom += 1);
	(key == 78) && (data->zoom -= 1);
	(key == 53) && (ft_malloc(0, 2), 0);
	data = key_hooks2(key, data);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, 1500, 1000);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	draw(data->map, p, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	ft_exit(void)
{
	exit(0);
}

int	main(int ac, char **av)
{
	t_point	p;
	t_data	*data;

	data = ft_malloc(sizeof(t_data), 1);
	if (!data)
		ft_malloc(0, 0);
	data->map = NULL;
	if (ac == 2)
	{
		data->map = parsing(av[1], &p);
		(!data->map) && (ft_malloc(0, 0));
		initialize(data, &p, av[1]);
		data->mlx = mlx_init();
		data->win = mlx_new_window(data->mlx, 1500, 1000, "FDF");
		data->img = mlx_new_image(data->mlx, 1500, 1000);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		draw(data->map, p, data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		mlx_hook(data->win, 2, 1L << 0, key_hooks, data);
		mlx_hook(data->win, 17, 0, ft_exit, &data);
		mlx_loop(data->mlx);
	}
	ft_malloc(0, 2);
	return (0);
}
