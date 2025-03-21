/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:55:41 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/21 21:17:21 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int	julia_equation(t_data *f, int x, int y)
{
	int		iter;
	double	temp_reel;

	iter = 1;
	f->z_re = f->x_min + ((double)x / WIDTH) * (f->x_max - f->x_min);
	f->z_im = f->y_min + ((double)y / HEIGHT) * (f->y_max - f->y_min);
	f->c_re = f->julia_re;
	f->c_im = f->julia_im;
	while (iter <= f->iteration)
	{
		temp_reel = f->z_re;
		f->z_re = (
				f->z_re * f->z_re) - (f->z_im * f->z_im) + f->c_re;
		f->z_im = (2 * temp_reel * f->z_im) + f->c_im;
		if ((f->z_re * f->z_re + f->z_im * f->z_im) > 4.0)
			return (iter);
		iter++;
	}
	return (iter);
}

static int	mandel_equation(t_data *f, int x, int y)
{
	int		iter;
	double	temp_reel;

	iter = 1;
	f->z_re = 0;
	f->z_im = 0;
	f->c_re = f->x_min + ((double)x / WIDTH) * (f->x_max - f->x_min);
	f->c_im = f->y_min + ((double)y / HEIGHT) * (f->y_max - f->y_min);
	while (iter <= f->iteration)
	{
		temp_reel = f->z_re;
		f->z_re = (
				f->z_re * f->z_re) - (f->z_im * f->z_im) + f->c_re;
		f->z_im = (2 * temp_reel * f->z_im) + f->c_im;
		if ((f->z_re * f->z_re + f->z_im * f->z_im) > 4.0)
			return (iter);
		iter++;
	}
	return (iter);
}

static void	calc_pixel(t_data *f, int (*equation)(t_data*, int, int))
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
			iter = equation(f, x, y);
			my_mlx_pixel_put(f, x, y, (iter * 0xEFCAE) / f->iteration);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->init, f->win, f->img, 0, 0);
}

void	calc_fractal(t_data *f)
{
	if (f->set == MANDELBROT)
		calc_pixel(f, mandel_equation);
	else if (f->set == JULIA)
		calc_pixel(f, julia_equation);
}
