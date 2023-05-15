/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:30:47 by asabri            #+#    #+#             */
/*   Updated: 2023/05/15 04:30:16 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void DDA(double x,double y,double x1,double y1,t_data *img)
{
    
    int i;
    double dx;
    double dy;
    double xinc;
    double yinc;
    int step;

    dx = x1 - x;
    dy = y1 - y;

    if (fabs(dx) > fabs(dy))
        step = fabs(dx);
    else
        step = fabs(dy);
    
    xinc = dx/step;
    yinc = dy/step;
    i = 0;

    while (i <= step)
    {
        my_mlx_pixel_put(img,x,y, 0x00FF0000);
        x = x + xinc;
        y = y + yinc;
        i++;
    }
}

void draw(t_map *map,t_data *img)
{
    int **mtr;
    int i;
    int j;

    i = 0;
    j = 0;
    while(map)
    {
        i = 0;
        mtr = map->x;
        while(mtr[i])
        {
            DDA(i + 1, j, i,j + 1,img); 
            i++;
        }
        j++;
        map = map->next;
    }
}