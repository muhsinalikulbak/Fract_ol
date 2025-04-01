/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:47:20 by mkulbak           #+#    #+#             */
/*   Updated: 2025/04/01 14:55:57 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <stdio.h>

int	key_hook(int keycode, t_data *f)
{
	if (keycode == KEY_ESC)
		mlx_destroy(f);
	else if (keycode == KEY_SPACE)
		change_palette(f);
	else if (keycode >= KEY_ONE && keycode <= KEY_FIVE)
		change_set(f, keycode);
	else if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
		move(f, keycode);
	else if (keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_RIGHT || keycode == KEY_LEFT)
		move(f, keycode);
	else if (keycode == KEY_J || keycode == KEY_K)
	{
		change_iter(f, keycode);
		return (0);
	}
	else if (keycode == KEY_G)
	{
		f->gradian = !f->gradian;
	}
	else
		return (0);
	calc_fractal(f);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *f)
{
	int	key;

	key = zoom(keycode, x, y, f);
	if (key == EXIT_SUCCESS)
		calc_fractal(f);
	return (0);
}

int	track_mouse_position(t_data *f)
{
	int	x;
	int	y;

	if (f->set == DYNAMIC_JULIA)
	{
		mlx_mouse_get_pos(f->init, f->win, &x, &y);
		f->dy_julia_re = f->x_min + ((double)x / WIDTH) * (
				f->x_max - f->x_min);
		f->dy_julia_im = f->y_min + ((double)y / HEIGHT) * (
				f->y_max - f->y_min);
		printf("x = %f y = %f\n", f->dy_julia_re, f->dy_julia_im);
		calc_fractal(f);
	}
	return (0);
}
