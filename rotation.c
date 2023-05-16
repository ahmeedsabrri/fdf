/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:06:25 by asabri            #+#    #+#             */
/*   Updated: 2023/05/16 01:46:39 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
double degree_to_radian(int degree)
{
    double radian;

    radian = degree * (M_PI / 180.0);
    return (radian);
}

t_point rotation(t_point p, t_data *data)
{
    t_point p1;
    data->sy = 500;
    data->sx = 200;
    data->rx = degree_to_radian(45);
    data->ry = degree_to_radian(45);
    data->rz = degree_to_radian(-30);
    p1 = p;
	p1.x = p.x;
	p1.y = p.y * cos(data->rx) - (p.z * sin(data->rx));
	p1.z = p.y * sin(data->rx) + p.z * cos(data->rx);
	p = p1;
	p.x = p1.x * cos(data->ry) + p1.z * sin(data->ry);
	p.y = p1.y;
	p.z = p1.x * -sin(data->ry) + p1.z * cos(data->ry);
	p1 = p;
	p1.x = p.x * cos(data->rz) + p.y * -sin(data->rz);
	p1.y = p.x * sin(data->rz) + p.y * cos(data->rz);
	p1.z = p.z;
	p.y = p1.y + data->sy;
	p.x = p1.x + data->sx;
    return (p);
}