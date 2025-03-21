/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:55:41 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/21 17:36:04 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int	julia_equation(t_data *set, int x, int y)
{
	int		iter;
	double	temp_reel;

	iter = 1;
	set->z_re = set->x_min + ((double)x / WIDTH) * (set->x_max - set->x_min);
	set->z_im = set->y_min + ((double)y / HEIGHT) * (set->y_max - set->y_min);
	set->c_re = set->julia_re;
	set->c_im = set->julia_im;
	while (iter <= set->iteration)
	{
		temp_reel = set->z_re;
		set->z_re = (
				set->z_re * set->z_re) - (set->z_im * set->z_im) + set->c_re;
		set->z_im = (2 * temp_reel * set->z_im) + set->c_im;
		if ((set->z_re * set->z_re + set->z_im * set->z_im) > 4.0)
			return (iter);
		iter++;
	}
	return (iter);
}

static int	mandel_equation(t_data *set, int x, int y)
{
	int		iter;
	double	temp_reel;

	iter = 1;
	set->z_re = 0;
	set->z_im = 0;
	set->c_re = set->x_min + ((double)x / WIDTH) * (set->x_max - set->x_min);
	set->c_im = set->y_min + ((double)y / HEIGHT) * (set->y_max - set->y_min);
	while (iter <= set->iteration)
	{
		temp_reel = set->z_re;
		set->z_re = (
				set->z_re * set->z_re) - (set->z_im * set->z_im) + set->c_re;
		set->z_im = (2 * temp_reel * set->z_im) + set->c_im;
		if ((set->z_re * set->z_re + set->z_im * set->z_im) > 4.0)
			return (iter);
		iter++;
	}
	return (iter);
}

static void	calc_pixel(t_data *data, int (*equation)(t_data*, int, int))
{
	int		x;
	int		y;
	double	iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			iter = equation(data, x, y);
			my_mlx_pixel_put(data, x, y, (iter * 0xEFCAE) / data->iteration);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->init, data->win, data->img, 0, 0);
}

int	calc_fractal(t_data *data)
{
	if (data->set == MANDELBROT)
		calc_pixel(data, mandel_equation);
	else if (data->set == JULIA)
		calc_pixel(data, julia_equation);
}
