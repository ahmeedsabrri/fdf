/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:19:20 by asabri            #+#    #+#             */
/*   Updated: 2023/03/16 09:41:01 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// Function for finding absolute value
int abs(int n) 
{ 
    return ((n > 0) ? n : (n * (-1))); 
}

void    ft_DDA(int x, int y, int x1, int y1,fdf *data)// (1,1) (3,12)
{
    int dx;
    int dy;
    // calculate dx & dy
    dx = x1 - x;
    dy = y1 - y;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    // calculate increment in x & y for each steps
    float Xinc;
    float Yinc;

    Xinc = dx / (float)steps;
    Yinc = dy / (float)steps;
}