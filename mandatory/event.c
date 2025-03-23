/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:47:20 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/23 16:54:39 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int	zoom(int keycode, t_data *f)
{
	double	range_x;
	double	range_y;

	range_x = f->x_max - f->x_min;
	range_y = f->y_max - f->y_min;
	if (keycode == SCROOL_UP)
	{
		f->x_max -= range_x * 0.2;
		f->x_min += range_x * 0.2;
		f->y_max -= range_y * 0.2;
		f->y_min += range_y * 0.2;
	}
	if (keycode == SCROOL_DOWN)
	{
		f->x_max += range_x * 0.2;
		f->x_min -= range_x * 0.2;
		f->y_max += range_y * 0.2;
		f->y_min -= range_y * 0.2;
	}
	return (0);
}

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
		f->x_max -= range_x * distance;
		f->x_min -= range_x * distance;
	}
	if (keycode == KEY_D)
	{
		f->x_max += range_x * distance;
		f->x_min += range_x * distance;
	}
}

int	key_event(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		mlx_destroy(data);
	if (keycode == KEY_W)
		move(data, 0.2, KEY_W);
	if (keycode == KEY_A)
		move(data, 0.2, KEY_A);
	if (keycode == KEY_S)
		move(data, 0.2, KEY_S);
	if (keycode == KEY_D)
		move(data, 0.2, KEY_D);
	calc_fractal(data);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *f)
{
	(void)x;
	(void)y;
	if (keycode == SCROOL_UP)
		zoom(SCROOL_UP, f);
	if (keycode == SCROOL_DOWN)
		zoom(SCROOL_DOWN, f);
	calc_fractal(f);
	return (0);
}
