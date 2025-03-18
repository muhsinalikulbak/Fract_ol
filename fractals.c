/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:55:41 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/19 01:18:34 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int  julia_equation(t_coordinates *coord, int x, int y)
{
	int		iteration_count;
	double	temp_reel;

	iteration_count = 1;
	coord->z_im = coord->y_min + ((double)y / HEIGHT) * (coord->y_max - coord->y_min);
	coord->z_re = coord->x_min + ((double)x / WIDTH) * (coord->x_max - coord->x_min);
	coord->c_re = coord->julia_re;
	coord->c_im = coord->julia_im;
	while (iteration_count <= coord->iteration)
	{
		temp_reel = coord->z_re;
		coord->z_re = (coord->z_re * coord->z_re) - (coord->z_im * coord->z_im) + coord->c_re;
		coord->z_im = (2 * temp_reel * coord->z_im ) + coord->c_im;
		if ((coord->z_re * coord->z_re + coord->z_im * coord->z_im) > 4.0)
			return iteration_count;
		iteration_count++;
	}
	return iteration_count;
}

static int  mandel_equation(t_coordinates *coord, int x, int y)
{
	int		iteration_count;
	double	temp_reel;

	iteration_count = 1;
	coord->z_im = 0;
	coord->z_re = 0;
	coord->c_re = coord->x_min + ((double)x / WIDTH) * (coord->x_max - coord->x_min);
	coord->c_im = coord->y_min + ((double)y / HEIGHT) * (coord->y_max - coord->y_min);
	while (iteration_count <= coord->iteration)
	{
		temp_reel = coord->z_re;
		coord->z_re = (coord->z_re * coord->z_re) - (coord->z_im * coord->z_im) + coord->c_re;
		coord->z_im = (2 * temp_reel * coord->z_im ) + coord->c_im;
		if ((coord->z_re * coord->z_re + coord->z_im * coord->z_im) > 4.0)
			return iteration_count;
		iteration_count++;
	}
	return iteration_count;
}

void	calc_pixel(t_mlx_data *data, t_coordinates *coord)
{
	int		x;
	int		y;
	double	iteration_count;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			iteration_count = mandel_equation(coord, x, y);
			my_mlx_pixel_put(data, x, y, (iteration_count * 0xEFCAE) / coord->iteration);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->init, data->win, data->img, 0, 0);
}
