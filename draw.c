/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:30:47 by asabri            #+#    #+#             */
/*   Updated: 2023/05/16 02:38:52 by asabri           ###   ########.fr       */
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

t_point	update_dist(t_point p, t_data *ptr)
{
	int	dw;
	int	dm;
	int	dist;

	dw = sqrt(pow(1500, 2) + pow(1000, 2));
	dm = sqrt(pow(ptr->xup, 2) + pow(ptr->yup, 2));
	dist = ((dw * 50) / 100) / dm;
	if (dist < 2 && !ptr->zoom)
		dist = 2;
	p.x *= (dist + ptr->zoom);
	p.y *= (dist + ptr->zoom);
	p.x -= (ptr->xup * dist) / 2;
	p.y -= (ptr->yup * dist) / 2;
	if (p.z)
		p.z *= ptr->nz + 1;
	p = rotation(p, ptr);
	p.x += 750 ;
	p.y += 500 ;
	p.c += ((0xaaaa + ptr->nc) * (ptr->nc * 10));
    return (p);
}

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
            p.z = mtr[i][0];
            p.c = mtr[i][1];
            p.y = j;
            p.x = i;
            // printf("line = %d p1.z = %f\n", j, p.z);
            // seconde point
            if (map->next)
            {   
                p1.x = i;
                p1.y = (j + 1) ;
                p1.z = map->next->x[i][0];
                p1.c = map->next->x[i][1];
                // printf("j = %d i = %d p1.z = %f\n",j, i , p1.z);
            }
            // third point
            if (mtr[i + 1]!= NULL)
            {   
                p2.x = (i + 1) ;
                p2.y = j ;
                p2.z = mtr[i + 1][0];
                p2.c = mtr[i + 1][1];
            }
            
            
            p = update_dist(p,data);
            p1 = update_dist(p1,data);
            p2 = update_dist(p2,data);
            // p = rotation(p, data);
            // p1 = rotation(p1, data);
            // p2 = rotation(p2, data);
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