/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:47:20 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/25 19:27:45 by mkulbak          ###   ########.fr       */
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
	if (keycode == KEY_W)
	{
		f->y_max -= range_y * f->move_factor;
		f->y_min -= range_y * f->move_factor;
	}
	if (keycode == KEY_S)
	{
		f->y_max += range_y * f->move_factor;
		f->y_min += range_y * f->move_factor;
	}
	if (keycode == KEY_A)
	{
		f->x_max -= range_x * f->move_factor;
		f->x_min -= range_x * f->move_factor;
	}
	if (keycode == KEY_D)
	{
		f->x_max += range_x * f->move_factor;
		f->x_min += range_x * f->move_factor;
	}
}

int	key_event(int keycode, t_data *f)
{
	if (keycode == KEY_ESC)
		mlx_destroy(f);
	move(f, keycode);
	calc_fractal(f);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *f)
{
	(void)x;
	(void)y;
	zoom(keycode, f);
	calc_fractal(f);
	return (0);
}
