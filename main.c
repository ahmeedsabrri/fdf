/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 03:02:14 by asabri            #+#    #+#             */
/*   Updated: 2023/05/19 10:14:11 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize(t_data *data, t_point *p, char *fn)
{
	p->x = 0;
	p->y = 0;
	p->z = 0;
	p->c = 0;
	data->nc = 0;
	data->nz = 1;
	data->width_x = p->width;
	data->height_y = p->height;
	data->zoom = 0;
	data->sy = 0;
	data->sx = 0;
	data->angle_x = 45;
	data->angle_y = 45;
	data->angle_z = -35;
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
	(key == 126) && (data->angle_x += 1);
	(key == 125) && (data->angle_x -= 1);
	(key == 123) && (data->angle_y += 1);
	(key == 124) && (data->angle_y -= 1);
	(key == 117) && (data->angle_z += 1);
	(key == 115) && (data->angle_z -= 1);
	if (key == 15)
	{
		data->angle_x = 45;
		data->angle_y = 45;
		data->angle_z = -35;
	}
	else if (key == 3)
	{
		data->angle_x = 0;
		data->angle_y = 0;
		data->angle_z = 0;
	}
	return (data);
}

int	key_hooks(int key, t_data *data)
{
	(key == 69) && (data->zoom += 1);
	(key == 78) && (data->zoom -= 1);
	(key == 53) && (ft_malloc(0, 2), 0);
	data = key_hooks2(key, data);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, 1500, 1000);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	draw(data->map, *(data->p), data);
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
	t_map	*map;
	t_data	*data;

	data = ft_malloc(sizeof(t_data), 1);
	if (!data)
		ft_malloc(0, 0);
	map = NULL;
	if (ac > 2 || ac < 2)
		return (write(2, "invalid args\n", 14), ft_malloc(0, 0), 0);
	if (ac == 2)
	{
		map = parsing(av[1], &p);
		(!data->map) && (ft_malloc(0, 0));
		initialize(data, &p, av[1]);
		data->map = map;
		mlx_utils_init(data);
		draw(map, p, data);
		data->p = &p;
		mlx_utils_hooks(data);
	}
	ft_malloc(0, 2);
	return (0);
}
