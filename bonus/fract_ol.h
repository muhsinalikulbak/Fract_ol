/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:20:24 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/26 01:11:45 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# define WIDTH 800
# define HEIGHT 800
# define MANDELBROT 1
# define JULIA 2
# define TRICORN 3
# define BURNING_SHIP 4
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"
# include "keys.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

typedef struct s_data
{
	void	*init;
	void	*img;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		set;
	double	iteration;
	double	inc;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	z_re;
	double	z_im;
	double	c_re;
	double	c_im;
	double	julia_re;
	double	julia_im;
	double	zoom_factor;
	double	move_factor;
	double	color_palette;
}				t_data;
typedef struct s_range
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}				t_range;

void	argv_check(int argc, char **argv);
void	my_mlx_pixel_put(t_data	*data, int x, int y, int color);
void	initializer(t_data *data, char **argv, int argc);
void	calc_fractal(t_data *data);
int		mlx_destroy(t_data *data);
int		key_event(int keycode, t_data *data);
void	realloc_image(t_data *f);
int		mouse_hook(int keycode, int x, int y, t_data *f);
int		mandel_equation(t_data *f, int x, int y);
int		julia_equation(t_data *f, int x, int y);
int		tricorn_equation(t_data *f, int x, int y);
int		burning_ship_equation(t_data *f, int x, int y);
t_range	mandel_scale(void);
t_range	julia_scale(void);
t_range	tricorn_scale(void);
t_range	burning_ship_scale(void);
#endif