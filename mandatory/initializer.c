/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:51:55 by mkulbak           #+#    #+#             */
/*   Updated: 2025/04/07 20:37:12 by mkulbak          ###   ########.fr       */
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

static void	scaling(t_data *f, t_range range)
{
	double	aspect_ratio;
	double	range_x;
	double	range_y;
	double	center_x;
	double	center_y;

	aspect_ratio = (double)WIDTH / (double)HEIGHT;
	range_x = range.x_max - range.x_min;
	range_y = range.y_max - range.y_min;
	center_x = (range.x_min + range.x_max) / 2.0;
	center_y = (range.y_min + range.y_max) / 2.0;
	if (aspect_ratio > 1)
	{
		range.x_min = center_x - (range_x * aspect_ratio) / 2.0;
		range.x_max = center_x + (range_x * aspect_ratio) / 2.0;
	}
	else if (aspect_ratio < 1)
	{
		range.y_min = center_y - (range_y / aspect_ratio) / 2.0;
		range.y_max = center_y + (range_y / aspect_ratio) / 2.0;
	}
	f->x_min = range.x_min;
	f->x_max = range.x_max;
	f->y_min = range.y_min;
	f->y_max = range.y_max;
}

static void	coordinates_initializer(t_data *f, char **argv, int argc)
{
	if (f->set == MANDELBROT)
		scaling(f, mandel_scale());
	else if (f->set == JULIA)
	{
		scaling(f, julia_scale());
		if (argc == 4)
		{
			f->julia_re = ft_atod(argv[2]);
			f->julia_im = ft_atod(argv[3]);
		}
		else
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
}

void	initializer(t_data *data, char **argv, int argc)
{
	mlx_initializer(data, argv[1]);
	set_name_initalize(data, argv[1]);
	coordinates_initializer(data, argv, argc);
	data->iteration = 100;
	data->zoom_factor = 0.2;
	data->move_factor = 0.2;
}
