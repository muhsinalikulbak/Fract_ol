/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:47:20 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/21 22:31:05 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	move(t_data *f, double distance, int keycode)
{
	double	range_x;
	double	range_y;

	range_x = f->x_max - f->x_min;
	range_y = f->y_max - f->y_min;
	if (keycode == KEY_W)
	{
		f->y_max -= range_y * distance;
		f->y_min -= range_y * distance;
	}
	if (keycode == KEY_S)
	{
		f->y_max += range_y * distance;
		f->y_min += range_y * distance;
	}
	if (keycode == KEY_A)
	{
		
	}
	calc_fractal(f);
}

int	end_fractal(t_data *data)
{
	mlx_destroy_image(data->init, data->img);
	mlx_destroy_window(data->init, data->win);
	mlx_destroy_display(data->init);
	free(data->init);
	free(data);
	exit(EXIT_SUCCESS);
}

int	key_event(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		end_fractal(data);
	if (keycode == KEY_W)
		move(data, 0.1, KEY_W);
	if (keycode == KEY_A)
		move(data, 0.1, KEY_A);
	if (keycode == KEY_S)
		move(data, 0.1, KEY_S);
	if (keycode == KEY_D)
		move(data, 0.1, KEY_D);
	return (0);
}
