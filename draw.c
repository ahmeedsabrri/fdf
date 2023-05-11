/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:19:20 by asabri            #+#    #+#             */
/*   Updated: 2023/03/26 02:00:39 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void ft_rotate(double *x,double *y,int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z;
}

void    ft_DDA(double x, double y, double x1, double y1,t_fdf *data)// (1,1) (3,12)
{
    double dx;
    double dy;
    int i;
    int z;
    int z1;
    
    z = data->z[(int)y][(int)x];
    z1 = data->z[(int)y1][(int)x1];
    //Zoom multiply
    x *= data->zoom;
    y *= data->zoom;
    x1 *= data->zoom;
    y1 *= data->zoom;
    //color
    //data->color = (z) ? 0xe80c0c : 0xffffff;
    if (z || z1)
        data->color = 0xe80c0c;
    else
        data->color = 0xffffff;
    // 3d rotation 
    ft_rotate(&x,&y,z);
    ft_rotate(&x1,&y1,z1);

    // shifting 
    x += 500;
    y += 500;
    x1 += 500;
    y1 += 500;
    // calculate dx & dy
    dx = x1 - x;
    dy = y1 - y;
    double steps;
    steps = fmax(fabs(dx), fabs (dy));
    //  = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    // calculate increment in x & y for each steps
    double Xinc;
    double Yinc;

    Xinc = dx / steps;
    Yinc = dy / steps;
    i = 0;
    while (i < steps)
    {
       //mlx_pixel_put(data->mlx_ptr,data->win_ptr,x*data->scale,y*data->scale,data->color);
        // if (z > 0 || z1 > 0)
        // {
        //     my_mlx_pixel_put(data,x*data->scale,y*data->scale,data->color);
        // }
        if (x < 1000 && y < 1000 && x >0 && y > 0)
            my_mlx_pixel_put(data,x,y,data->color);
        x = x + Xinc;
        y = y + Yinc;
        i++;
    }

}

void draw(t_fdf *data)
{
    int x;
    int y;

    y = 0;
    
    while (y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
            if (x < data->width - 1)
                ft_DDA(x,y,x + 1,y,data);
            if (y < data->height - 1)
                ft_DDA(x,y,x,y + 1,data);
            x++;
        }
        y++;
    }
    
}