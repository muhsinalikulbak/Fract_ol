/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:51:55 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/21 00:49:06 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	mlx_initializer(t_data *data, char *set_name)
{
	data->init = mlx_init();
	data->win = mlx_new_window(data->init, WIDTH, HEIGHT, set_name);
	data->img = mlx_new_image(data->init, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img,
			&data->bits_per_pixel, &data->line_length, &data->endian);
}

static void	scaling(t_data *data, t_range range)
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
	data->x_min = range.x_min;
	data->x_max = range.x_max;
	data->y_min = range.y_min;
	data->y_max = range.y_max;
}

static void	coordinates_initializer(t_data *data, char **argv)
{
	if (data->set == MANDELBROT)
	{
		scaling(data, mandel_scale());
	}
	else if (data->set == JULIA)
	{
		scaling(data, julia_scale());
		data->julia_re = ft_atob(argv[2]);
		data->julia_im = ft_atob(argv[3]);
	}
}

static void	set_name_initalize(t_data *data, char **argv)
{
	if (ft_strncmp(argv[1], "Mandelbrot", 10))
		data->set = MANDELBROT;
	else if (ft_strncmp(argv[1], "Julia", 5))
		data->set = JULIA;
}

void	initializer(t_data *data, char **argv)
{
	mlx_initializer(data, argv[1]);
	set_name_initalize(data, argv);
	coordinates_initializer(data, argv);
	data->iteration = 300;
}
