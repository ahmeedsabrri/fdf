/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:32:31 by asabri            #+#    #+#             */
/*   Updated: 2023/03/26 02:02:50 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int manage_key(int keycode,t_fdf *data)
{
    if(keycode == 125)
    {
        data->scale +=0.01;
        mlx_destroy_image(data->mlx_ptr,data->img_ptr);
        data->img_ptr = mlx_new_image(data->mlx_ptr,1000,10000);
        draw(data);
        mlx_put_image_to_window(data->mlx_ptr,data->win_ptr,data->img_ptr,0,0);
    }
    if(keycode == 126)
    {
        data->scale -=0.01;
        mlx_destroy_image(data->mlx_ptr,data->img_ptr);
        data->img_ptr = mlx_new_image(data->mlx_ptr,1000,10000);
        draw(data);
        mlx_put_image_to_window(data->mlx_ptr,data->win_ptr,data->img_ptr,0,0);    
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    t_fdf *data;
    
    data = (t_fdf*)malloc(sizeof(t_fdf));
    data->scale=0.2;
    (void)argc;
    ft_read_map(argv[1],data);
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr,1000,1000, "fdf");
    data->img_ptr = mlx_new_image(data->mlx_ptr,1000,10000);
    data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, &data->line_length,
								&data->endian);
    data->zoom = 3;
    // ft_DDA(11,10,600,300,data);
    draw(data);
    mlx_put_image_to_window(data->mlx_ptr,data->win_ptr,data->img_ptr,0,0);
    mlx_hook(data->win_ptr,2,0,manage_key,data);
    mlx_loop(data->mlx_ptr);
    return 0;
}