/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:30:47 by asabri            #+#    #+#             */
/*   Updated: 2023/05/16 01:45:39 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void DDA(double x,double y,double x1,double y1,t_data *data,t_point p)
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
        mlx_pixel_put(data->mlx,data->win,x,y,p.c);
        x = x + xinc;
        y = y + yinc;
        i++;
    }
}

// t_point update_dist(t_point p1,t_point p2,t_data *data)
// {
    
//     double dist;

//     dist = (pow(p2.x - p1.x) * 2) + (pow(p2.y - p1.y) * 2)
// }

void draw(t_map *map,t_point p,t_data *data)
{
    t_point p1;
    t_point p2;
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
            // first point
            p.z = mtr[i][0] * 2;
            p.c = mtr[i][1];
            p.y = j * 20;
            p.x = i * 20;
            // printf("line = %d p1.z = %f\n", j, p.z);
            // seconde point
            if (map->next)
            {   
                p1.x = i * 20;
                p1.y = (j + 1) * 20;
                p1.z = map->next->x[i][0] * 2;
                p1.c = map->next->x[i][1];
                // printf("j = %d i = %d p1.z = %f\n",j, i , p1.z);
            }
            // third point
            if (mtr[i + 1]!= NULL)
            {   
                p2.x = (i + 1) * 20;
                p2.y = j * 20;
                p2.z = mtr[i + 1][0] * 2;
                p2.c = mtr[i + 1][1];
            }
            
            p = rotation(p,data);
            p1 = rotation(p1,data);
            p2 = rotation(p2,data);
            if (i < p.width - 1 )
                DDA(p.x ,p.y ,p2.x ,p2.y ,data,p);
            if (j < p.height - 1 )
                DDA(p.x ,p.y ,p1.x ,p1.y ,data,p);
            i++;
        }
        // puts("\n");
        j++;
        map = map->next;
    }
}