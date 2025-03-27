/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:47:20 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/27 13:29:18 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int	zoom(int keycode, int x, int y, t_data *f)
{
	double	mouse_x;
	double	mouse_y;

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

static void	change_set(t_data *f, int keycode)
{
	if (keycode == KEY_ONE)
	{
		f->set = MANDELBROT;
		coordinates_initializer(f, NULL, 0);
	}
	else if (keycode == KEY_TWO)
	{
		f->set = JULIA;
		coordinates_initializer(f, NULL, 2);
	}
	else if (keycode == KEY_THREE)
	{
		f->set = TRICORN;
		coordinates_initializer(f, NULL, 0);
	}
	else if (keycode == KEY_FOUR)
	{
		f->set = BURNING_SHIP;
		coordinates_initializer(f, NULL, 0);
	}
}

int	key_event(int keycode, t_data *f)
{
	if (keycode == KEY_ESC)
		mlx_destroy(f);
	else if (keycode == KEY_SPACE)
		palette(f);
	else if (keycode >= KEY_ONE && keycode <= KEY_FOUR)
		change_set(f, keycode);
	else if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
		move(f, keycode);
	else if (keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_RIGHT || keycode == KEY_LEFT)
		move(f, keycode);
	else if (keycode == KEY_J || keycode == KEY_K )
	{
		change_iter(f, keycode);
		return (0);
	}
	else
		return (0);
	calc_fractal(f);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *f)
{
	zoom(keycode, x, y, f);
	calc_fractal(f);
	return (0);
}
