/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:32:31 by asabri            #+#    #+#             */
/*   Updated: 2023/03/16 09:36:12 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     deal_key(int key, void *data)
{
    (void)data;
    printf("%d", key);
    return (0);
}

int main(int argc, char const *argv[])
{
    fdf *data;
    
    data = (fdf*)malloc(sizeof(fdf));
    (void)argc;
    ft_read_map(argv[1],data);
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr,1000,1000, "FDF");
    ft_DDA(10,10,600,300,data);
    mlx_key_hook(data->mlx_ptr,deal_key,NULL);
    mlx_loop(data->mlx_ptr);
    return 0;
}