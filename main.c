/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 03:02:14 by asabri            #+#    #+#             */
/*   Updated: 2023/05/12 22:48:31 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
int main(int ac, char **av)
{
    t_map *data;
    
    data = NULL;
    if (ac == 2)
        data = parsing(av[1]);
    int i;
    int j;

    i = 0;
    j = 0;
    while (data->x)
    {
        while (data->x[i][j])
            printf("%d",data->x[i][j++]);
        i++;
        data = data->next;
    }
    return 0;
}
