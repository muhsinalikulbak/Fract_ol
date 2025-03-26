/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:55:41 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/26 03:00:15 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	calc_pixel(t_data *f, int (*equation)(t_data*, int, int))
{
	int		x;
	int		y;
	double	iter;

	if (f->img)
		realloc_image(f);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			iter = equation(f, x, y);
			my_mlx_pixel_put(f, x, y, (iter * f->palette) / f->iteration);
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
	else if (f->set == TRICORN)
		calc_pixel(f, tricorn_equation);
	else if (f->set == BURNING_SHIP)
		calc_pixel(f, burning_ship_equation);
}
