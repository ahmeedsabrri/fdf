/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:06:25 by asabri            #+#    #+#             */
/*   Updated: 2023/05/15 03:51:02 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point rotation(t_point point, t_data *data)
{
    t_point ptr;

    ptr = point;
    ptr.x = point.x;
    ptr.y = point.y * cos(data->rx) - point.z * sin(data->rx);
    ptr.z = point.y * sin(data->rx) + point.z * cos(data->rx);
    point = ptr;
    ptr.x = point.x * cos(data->ry) + point.z * sin(data->ry);
    ptr.y = point.y;
    ptr.z = point.x *(-sin(data->ry)) + point.z * (cos(data->ry));
    point =  ptr;
    ptr.x = point.x * cos(data->rz) - point.y * sin(data->rz);
    ptr.y = point.x * sin(data->rz) + point.y * cos(data->rz);
    ptr.z = point.z;
    point = ptr;
    return (point);
}