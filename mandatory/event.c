/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:47:20 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/27 04:12:32 by mkulbak          ###   ########.fr       */
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
		f->x_max -= range_x * f->zoom_factor;
		f->x_min += range_x * f->zoom_factor;
		f->y_max -= range_y * f->zoom_factor;
		f->y_min += range_y * f->zoom_factor;
	}
	if (keycode == SCROOL_DOWN)
	{
		f->x_max += range_x * f->zoom_factor;
		f->x_min -= range_x * f->zoom_factor;
		f->y_max += range_y * f->zoom_factor;
		f->y_min -= range_y * f->zoom_factor;
	}
	return (0);
}

static void	move(t_data *f, int keycode)
{
	double	range_x;
	double	range_y;

	range_x = f->x_max - f->x_min;
	range_y = f->y_max - f->y_min;
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		f->y_max -= range_y * f->move_factor;
		f->y_min -= range_y * f->move_factor;
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		f->y_max += range_y * f->move_factor;
		f->y_min += range_y * f->move_factor;
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		f->x_max -= range_x * f->move_factor;
		f->x_min -= range_x * f->move_factor;
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		f->x_max += range_x * f->move_factor;
		f->x_min += range_x * f->move_factor;
	}
}

int	key_event(int key, t_data *f)
{
	if (key == KEY_ESC)
		mlx_destroy(f);
	if (key == KEY_W || key == KEY_A || key == KEY_S
		|| key == KEY_D || key == KEY_DOWN || key == KEY_UP
		|| key == KEY_RIGHT || key == KEY_LEFT)
	{
		move(f, key);
		calc_fractal(f);
	}
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *f)
{
	(void)x;
	(void)y;
	if (keycode == SCROOL_DOWN || keycode == SCROOL_UP)
	{
		zoom(keycode, f);
		calc_fractal(f);
	}
	return (0);
}
