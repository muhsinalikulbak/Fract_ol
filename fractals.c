/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:55:41 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/20 00:23:46 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int	julia_equation(t_set_data *set, int x, int y)
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

static int	mandel_equation(t_set_data *set, int x, int y)
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

static void	calc_pixel(t_mlx_data *data, t_set_data *set,
		int (*equation)(t_set_data*, int, int))
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
			iter = equation(set, x, y);
			my_mlx_pixel_put(data, x, y, (iter * 0xEFCAE) / set->iteration);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->init, data->win, data->img, 0, 0);
}

int	calc_fractal(t_mlx_data *data, t_set_data *set)
{
	if (set->set == MANDELBROT)
		calc_pixel(data, set, mandel_equation);
	else if (set->set == JULIA)
		calc_pixel(data, set, julia_equation);
}
