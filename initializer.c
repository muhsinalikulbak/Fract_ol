/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:51:55 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/19 01:46:39 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	mlx_initializer(t_mlx_data *data, char *set_name)
{
	data->init = mlx_init();
	data->win = mlx_new_window(data->init, WIDTH, HEIGHT, set_name);
	data->img = mlx_new_image(data->init, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img,
			&data->bits_per_pixel, &data->line_length, &data->endian);
}

static void	scaling(t_coordinates *coord, t_range range)
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
	coord->x_min = range.x_min;
	coord->x_max = range.x_max;
	coord->y_min = range.y_min;
	coord->y_max = range.y_max;
}

static void	coordinates_initializer(t_coordinates *coord)
{
	if (coord->set == MANDELBROT)
	{
		scaling(coord, mandel_scale());
	}
	else if (coord->set == JULIA)
	{
		scaling(coord, julia_scale());
	}
}

static void	set_name_initalize(t_coordinates *coord, char **argv)
{
	if (ft_strncmp(argv[1], "Mandelbrot", 10))
		coord->set = MANDELBROT;
	else if (ft_strncmp(argv[1], "Julia", 5))
		coord->set = JULIA;
}

void	initializer(t_mlx_data *data, t_coordinates *coord, char **argv)
{
	mlx_initializer(data, argv[1]);
	set_name_initalize(coord, argv);
	coordinates_initializer(coord);
	coord->iteration = 300;
}
