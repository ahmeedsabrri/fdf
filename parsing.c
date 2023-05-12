/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 02:49:57 by asabri            #+#    #+#             */
/*   Updated: 2023/05/12 05:05:36 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
char *readlines(chat *file_name)
{
    int fd;
    char *line;
    
    fd = open(file_name,O_RDWR | 777);
    line = get_next_line(fd);
    if (line)
    {
        while (line)
            return (free(line),line);  
    }
    else
        return (NULL);
    
}
int **parsing(char *file_name)
{
    char *line;
    char **mtr;
    int i;

    i = 0;
    line = readlines(file_name);
    if (line)
    {
        mtr = ft_split(line,' ');
        // while (mtr){
        //     printf("%s"mtr[i]);
        //     i++;
        // }
    }
    
}