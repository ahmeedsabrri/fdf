/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:06:25 by asabri            #+#    #+#             */
/*   Updated: 2023/05/17 05:56:37 by asabri           ###   ########.fr       */
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
	p1.y = p.y * cos(degree_to_radian(data->rx))
		- p.z * sin(degree_to_radian(data->rx));
	p1.z = p.y * sin(degree_to_radian(data->rx))
		+ p.z * cos(degree_to_radian(data->rx));
	p = p1;
	p.x = p1.x * cos(degree_to_radian(data->ry))
		+ p1.z * sin(degree_to_radian(data->ry));
	p.y = p1.y;
	p.z = p1.x * -sin(degree_to_radian(data->ry))
		+ p1.z * cos(degree_to_radian(data->ry));
	p1 = p;
	p1.x = p.x * cos(degree_to_radian(data->rz))
		+ p.y * -sin(degree_to_radian(data->rz));
	p1.y = p.x * sin(degree_to_radian(data->rz))
		+ p.y * cos(degree_to_radian(data->rz));
	p1.z = p.z;
	p.y = p1.y + data->sy;
	p.x = p1.x + data->sx;
	return (p);
}
