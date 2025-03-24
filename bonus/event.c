/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:47:20 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/25 02:11:03 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int zoom(int keycode, int x, int y, t_data *f)
{
	double mouse_x;
	double mouse_y;

	mouse_x = f->x_min + ((double)x / WIDTH) * (f->x_max - f->x_min);
	mouse_y = f->y_min + ((double)y / HEIGHT) * (f->y_max - f->y_min);
	if (keycode == SCROOL_UP)
	{
		f->x_min -= (f->x_min - mouse_x) * f->zoom_factor;
		f->x_max -= (f->x_max - mouse_x) * f->zoom_factor;
		f->y_min -= (f->y_min - mouse_y) * f->zoom_factor;
		f->y_max -= (f->y_max - mouse_y) * f->zoom_factor;
	}
	else if (keycode == SCROOL_DOWN)
	{
		f->x_min += (f->x_min - mouse_x) * f->zoom_factor;
		f->x_max += (f->x_max - mouse_x) * f->zoom_factor;
		f->y_min += (f->y_min - mouse_y) * f->zoom_factor;
		f->y_max += (f->y_max - mouse_y) * f->zoom_factor;
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

int	key_event(int keycode, t_data *f)
{
	if (keycode == KEY_ESC)
		mlx_destroy(f);
	if (keycode == KEY_W)
		move(f, f->move_factor, KEY_W);
	if (keycode == KEY_A)
		move(f, f->move_factor, KEY_A);
	if (keycode == KEY_S)
		move(f, f->move_factor, KEY_S);
	if (keycode == KEY_D)
		move(f, f->move_factor, KEY_D);
	calc_fractal(f);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *f)
{
	if (keycode == SCROOL_UP)
		zoom(SCROOL_UP, x, y, f);
	if (keycode == SCROOL_DOWN)
		zoom(SCROOL_DOWN, x, y, f);
	calc_fractal(f);
	return (0);
}
