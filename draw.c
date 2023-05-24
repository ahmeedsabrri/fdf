/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:30:47 by asabri            #+#    #+#             */
/*   Updated: 2023/05/19 09:54:47 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	ft_fabs(double dx, double dy)
{
	if (fabs(dx) > fabs(dy))
		return (fabs(dx));
	else
		return (fabs(dy));
}

void	dda(t_data *data, t_point p, t_point p1)
{
	double	dx;
	double	dy;
	double	xinc;
	double	yinc;
	int		step;

	dx = p1.x - p.x;
	dy = p1.y - p.y;
	step = ft_fabs(dx, dy);
	xinc = dx / step;
	yinc = dy / step;
	while (step--)
	{
		if (p.x > 0 && p.x < 1500 && p.y < 1000 && p.y > 0)
		{
			my_mlx_pixel_put(data, p.x, p.y, p.c);
			p.x = p.x + xinc;
			p.y = p.y + yinc;
		}
	}
}

t_point	update_dist(t_point p, t_data *data)
{
	int	dist_ref;
	int	dist_orgn;
	int	dst;

	dist_ref = sqrt(pow(1500, 2) + pow(1000, 2));
	dist_orgn = sqrt(pow(data->width_x, 2) + pow(data->height_y, 2));
	dst = ((dist_ref * 50) / 100) / dist_orgn;
	if (dst < 2 && !data->zoom)
		dst = 2;
	p.x *= (dst + data->zoom);
	p.y *= (dst + data->zoom);
	p.x -= (data->width_x * dst) / 2;
	p.y -= (data->height_y * dst) / 2;
	if (p.z)
		p.z *= data->nz;
	p = rotation(p, data);
	p.x += 750 ;
	p.y += 500 ;
	p.c += ((0xaaaa + data->nc) * (data->nc * 10));
	return (p);
}

t_point	fill_point(t_point p, int *str,	t_index n, t_data *data)
{
	(n.mode == 0) && (p.z = str[0], p.c = str[1], p.y = n.j, p.x = n.i);
	(n.mode == 1) && (p.x = n.i, p.y = n.j + 1, p.z = str[0], p.c = str[1]);
	(n.mode == 2) && (p.x = (n.i + 1), p.y = n.j, p.z = str[0], p.c = str[1]);
	p = update_dist(p, data);
	return (p);
}

void	draw(t_map *map, t_point p, t_data *data)
{
	t_point	p1;
	t_point	p2;
	t_index	n;
	int		**mtr;

	n.i = 0;
	n.j = 0;
	while (map)
	{
		n.i = -1;
		mtr = map->x;
		while (mtr[++n.i])
		{
			n.mode = 0;
			p = fill_point(p, mtr[n.i], n, data);
			(map->next) && (n.mode = 1,
				p1 = fill_point(p1, map->next->x[n.i], n, data), 0);
			(mtr[n.i + 1] != NULL) && (n.mode = 2,
				p2 = fill_point(p2, mtr[n.i + 1], n, data), 0);
			(n.i < p.width - 1) && (dda(data, p, p2), 0);
			(n.j < p.height - 1) && (dda(data, p, p1), 0);
		}
		n.j++;
		map = map->next;
	}
}
