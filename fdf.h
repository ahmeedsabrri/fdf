/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:32:21 by asabri            #+#    #+#             */
/*   Updated: 2023/03/16 09:29:29 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H  

# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct 
{
    int width;
    int height;
    int **z;

    void *mlx_ptr;
    void *win_ptr;
}       fdf;

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int	ft_atoi(const char *str);
int		ft_wdcounter(char const *str, char c);
void    ft_read_map(char const *map,fdf *data);
void    ft_DDA(int x, int y, int x1, int y1,fdf *data);
// int     deal_key(int key, void *data);
#endif // !FDF_H