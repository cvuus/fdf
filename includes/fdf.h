/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cosimavonuechtritz <cosimavonuechtritz@      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 10:03:42 by cuechtri      #+#    #+#                 */
/*   Updated: 2023/04/19 17:31:20 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define INT_MAX 2147483647;
# define INT_MIN -2147483648;
# define WIDTH 1366
# define HEIGHT 768
# define MENUWIDTH	250

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "get_next_line_bonus.h"
# include "../libft/libft.h"
# include "../libftprintf/ft_printf.h"

typedef struct s_point2d
{
	int			x;
	int			y;
	uint32_t	color;
}	t_point2d;

typedef struct s_map
{
	int	width;
	int	height;
	int	minz;
	int	maxz;
	int	centerx;
	int	centery;
	int	***cords;
}	t_map;

typedef struct s_camera
{
	int		zoom;
	double	alpha;
	double	beta;
	double	gamma;
	float	z_zoom;
	int		x_offset;
	int		y_offset;
	int		colortype;
}	t_camera;

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	mlx_image_t	*menu;
	t_camera	*camera;
	t_map		*map;
	int			steep;
}	t_fdf;

//Wu Line Algorithm
void		draw_line(t_point2d *a, t_point2d *b, t_fdf *fdf);

// Wu Line Algorithm Utils
float		ft_rfpart(float n);
int			ft_ipart(float n);
float		ft_fpart(float n);
int			ft_calculate_steep(t_point2d *a, t_point2d *b, t_fdf *fdf);

//fdf Utils
void		ft_swap(int *a, int *b);
void		ft_swap_uint32t(uint32_t *a, uint32_t *b);
char		**free_all(char **result);
float		ft_abs(float x);

//Key Hook
void		ft_hook(void *param);
void		zoom_hook(t_fdf *fdf);
void		color_hook(t_fdf *fdf);
void		translation_hook(t_fdf *fdf);
void		rotation_hook(t_fdf *fdf, mlx_image_t *image);

//Graphics Utils
void		ft_draw_menu(t_fdf *fdf);
void		ft_draw_background(mlx_image_t *image,
				int width, int height, int color);
void		ft_draw(t_fdf *fdf, t_camera *camera, t_map *map);
uint32_t	ft_pixel_color(int32_t r, int32_t g, int32_t b, int32_t a);
uint32_t	ft_color_gradient_pre(float percent, int color, int color2);
uint32_t	ft_color_gradient(int x, t_point2d p1, t_point2d p2);
uint32_t	ft_get_percentage_color(int pigment1, int pigment2, float percent);

//Coloring
void		ft_color_palette(t_map *map, t_camera *camera);

//fdf Initalizer
void		ft_init(t_camera *camera, t_map *map);

//Project
void		ft_rotation_matrix(t_camera *camera,
				t_point2d *point, double *zfinal);
void		ft_isometric(t_point2d *point, double z);
t_point2d	*ft_project(t_fdf *fdf, int x, int y, int zfinal);

//Translation

//fdf Input
int			get_dimensions(char *path, int *row, int *col);
int			init_map(t_map *map, char *name, int fd);
int			put_coordinates(t_map *map, int row, char *line);
int			put_splitted_nbr(char *splitted, t_map *map, int row, int col);
int			get_width(char *line);

#endif
