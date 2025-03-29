/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:51:55 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/30 01:30:17 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	mlx_initializer(t_data *mlx, char *set_name)
{
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, WIDTH, HEIGHT, set_name);
	mlx->img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img,
			&mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
}

static void	scaling(t_data *f, t_range scale)
{
	double	aspect_ratio;
	double	range_x;
	double	range_y;
	double	center_x;
	double	center_y;

	aspect_ratio = (double)WIDTH / (double)HEIGHT;
	range_x = scale.x_max - scale.x_min;
	range_y = scale.y_max - scale.y_min;
	center_x = (scale.x_min + scale.x_max) / 2.0;
	center_y = (scale.y_min + scale.y_max) / 2.0;
	if (aspect_ratio > 1)
	{
		scale.x_min = center_x - (range_x * aspect_ratio) / 2.0;
		scale.x_max = center_x + (range_x * aspect_ratio) / 2.0;
	}
	else if (aspect_ratio < 1)
	{
		scale.y_min = center_y - (range_y / aspect_ratio) / 2.0;
		scale.y_max = center_y + (range_y / aspect_ratio) / 2.0;
	}
	f->x_min = scale.x_min;
	f->x_max = scale.x_max;
	f->y_min = scale.y_min;
	f->y_max = scale.y_max;
}

void	coordinates_initializer(t_data *f, char **argv, int argc)
{
	if (f->set == MANDELBROT)
		scaling(f, mandel_scale());
	else if (f->set == TRICORN)
		scaling(f, tricorn_scale());
	else if (f->set == BURNING_SHIP)
		scaling(f, burning_ship_scale());
	else if (f->set == JULIA)
	{
		scaling(f, julia_scale());
		if (argc == 4)
		{
			f->julia_re = ft_atob(argv[2]);
			f->julia_im = ft_atob(argv[3]);
		}
		else if (argc == 2)
		{
			f->julia_re = -0.8;
			f->julia_im = 0.156;
		}
	}
}

static void	set_name_initalize(t_data *f, char *set)
{
	if (ft_strncmp(set, "Mandelbrot", 10))
		f->set = MANDELBROT;
	else if (ft_strncmp(set, "Julia", 5))
		f->set = JULIA;
	else if (ft_strncmp(set, "Tricorn", 7))
		f->set = TRICORN;
	else if (ft_strncmp(set, "Burning Ship", 12))
		f->set = BURNING_SHIP;
}

void	initializer(t_data *data, char **argv, int argc)
{
	mlx_initializer(data, argv[1]);
	set_name_initalize(data, argv[1]);
	coordinates_initializer(data, argv, argc);
	data->inc = 0.0;
	data->iteration = ITERATION;
	data->zoom_factor = 0.198567856;
	data->move_factor = 0.2;
	data->palette_code = 1;
	data->palette = 0xEFCAEE;
}
