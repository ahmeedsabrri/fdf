/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:06:25 by asabri            #+#    #+#             */
/*   Updated: 2023/05/19 09:58:04 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	degree_to_radian(int degree)
{
	double	radian;

	radian = degree * (M_PI / 180.0);
	return (radian);
}

t_point	rotation(t_point p, t_data *data)
{
	t_point	p1;

	p1 = p;
	p1.x = p.x;
	p1.y = p.y * cos(degree_to_radian(data->angle_x))
		- p.z * sin(degree_to_radian(data->angle_x));
	p1.z = p.y * sin(degree_to_radian(data->angle_x))
		+ p.z * cos(degree_to_radian(data->angle_x));
	p = p1;
	p.x = p1.x * cos(degree_to_radian(data->angle_y))
		+ p1.z * sin(degree_to_radian(data->angle_y));
	p.y = p1.y;
	p.z = p1.x * -sin(degree_to_radian(data->angle_y))
		+ p1.z * cos(degree_to_radian(data->angle_y));
	p1 = p;
	p1.x = p.x * cos(degree_to_radian(data->angle_z))
		+ p.y * -sin(degree_to_radian(data->angle_z));
	p1.y = p.x * sin(degree_to_radian(data->angle_z))
		+ p.y * cos(degree_to_radian(data->angle_z));
	p1.z = p.z;
	p.y = p1.y + data->sy;
	p.x = p1.x + data->sx;
	return (p);
}
