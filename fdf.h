/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:32:21 by asabri            #+#    #+#             */
/*   Updated: 2023/03/18 08:26:13 by asabri           ###   ########.fr       */
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

typedef struct s_fdf 
{
    int width;
    int height;
    int **z;
    int zoom;
    int color;
    int color2;
    double scale;

    void *mlx_ptr;
    void *win_ptr;

    void *img_ptr;
    char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}       t_fdf;

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
void    ft_read_map(char const *map,t_fdf *data);
void draw(t_fdf *data);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
// int     deal_key(int key, void *data);
#endif // !FDF_H