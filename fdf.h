/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 02:50:11 by asabri            #+#    #+#             */
/*   Updated: 2023/05/19 09:54:09 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft_42/libft.h"
# include "libftmalloc/ft_malloc.h"
# include "get_next_line.h"
# include <stdio.h>
# include <math.h>
# include<mlx.h>

typedef struct s_map
{
	int				**x;
	struct s_map	*next;
}				t_map;

typedef struct s_point
{
	int		height;
	int		width;
	double	x;
	double	y;
	int		z;
	double	c;
	int		mode;
}				t_point;
typedef struct s_data
{
	void			*mlx;
	void			*win;
	double			angle_x;
	double			angle_y;
	double			angle_z;

	int				sx;
	int				sy;
	int				zoom;
	int				width_x;
	int				height_y;
	int				nz;
	int				nc;

	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	char			*fl;

	struct s_map	*map;
	struct s_point	*p;
}				t_data;

typedef struct s_index
{
	int	i;
	int	j;
	int	mode;
}				t_index;
void	ft_lstadd_back(t_map **lst, t_map *new);
t_map	*ft_lstlast(t_map *lst);
t_map	*ft_lstnew(int **content);
int		ft_lstsize(t_map *list);
t_map	*parsing(char *arg, t_point *p);
int		**get_x(char *line, int *count);
int		*get_z(char *lwyen);
int		mtrlen(void **mtr);
int		hextodec(char *str);
void	draw(t_map *map, t_point p, t_data *data);
t_point	rotation(t_point point, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_hooks(int key, t_data *data);
t_data	*key_hooks2(int key, t_data *data);
int		ft_exit(void);
void	mlx_utils_hooks(t_data *data);
void	mlx_utils_init(t_data *data);
#endif