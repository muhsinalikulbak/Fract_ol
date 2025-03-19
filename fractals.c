/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:55:41 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/19 03:09:30 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int	julia_equation(t_set_data *c, int x, int y)
{
	int		iter;
	double	temp_reel;

	iter = 1;
	c->z_re = c->x_min + ((double)x / WIDTH) * (c->x_max - c->x_min);
	c->z_im = c->y_min + ((double)y / HEIGHT) * (c->y_max - c->y_min);
	c->c_re = c->julia_re;
	c->c_im = c->julia_im;
	while (iter <= c->iteration)
	{
		temp_reel = c->z_re;
		c->z_re = (c->z_re * c->z_re) - (c->z_im * c->z_im) + c->c_re;
		c->z_im = (2 * temp_reel * c->z_im) + c->c_im;
		if ((c->z_re * c->z_re + c->z_im * c->z_im) > 4.0)
			return (iter);
		iter++;
	}
	return (iter);
}

static int	mandel_equation(t_set_data *c, int x, int y)
{
	int		iter;
	double	temp_reel;

	iter = 1;
	c->z_re = 0;
	c->z_im = 0;
	c->c_re = c->x_min + ((double)x / WIDTH) * (c->x_max - c->x_min);
	c->c_im = c->y_min + ((double)y / HEIGHT) * (c->y_max - c->y_min);
	while (iter <= c->iteration)
	{
		temp_reel = c->z_re;
		c->z_re = (c->z_re * c->z_re) - (c->z_im * c->z_im) + c->c_re;
		c->z_im = (2 * temp_reel * c->z_im) + c->c_im;
		if ((c->z_re * c->z_re + c->z_im * c->z_im) > 4.0)
			return (iter);
		iter++;
	}
	return (iter);
}

static void	calc_pixel(t_mlx_data *data, t_set_data *c,
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
			iter = equation(c, x, y);
			my_mlx_pixel_put(data, x, y, (iter * 0xEFCAE) / c->iteration);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->init, data->win, data->img, 0, 0);
}

int	calc_fractal(t_mlx_data *data, t_set_data *c)
{
	if (c->set == MANDELBROT)
		calc_pixel(data, c, mandel_equation);
	else if (c->set == JULIA)
		calc_pixel(data, c, julia_equation);
}
