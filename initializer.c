/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:51:55 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/19 02:57:31 by mkulbak          ###   ########.fr       */
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

static void	scaling(t_set_data *set_data, t_range range)
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
	set_data->x_min = range.x_min;
	set_data->x_max = range.x_max;
	set_data->y_min = range.y_min;
	set_data->y_max = range.y_max;
}

static void	coordinates_initializer(t_set_data *set_data)
{
	if (set_data->set == MANDELBROT)
	{
		scaling(set_data, mandel_scale());
	}
	else if (set_data->set == JULIA)
	{
		scaling(set_data, julia_scale());
	}
}

static void	set_name_initalize(t_set_data *set_data, char **argv)
{
	if (ft_strncmp(argv[1], "Mandelbrot", 10))
		set_data->set = MANDELBROT;
	else if (ft_strncmp(argv[1], "Julia", 5))
		set_data->set = JULIA;
}

void	initializer(t_mlx_data *data, t_set_data *set_data, char **argv)
{
	mlx_initializer(data, argv[1]);
	set_name_initalize(set_data, argv);
	coordinates_initializer(set_data);
	set_data->iteration = 300;
}
