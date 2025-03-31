/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:47:20 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/31 03:52:52 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	key_hook(int keycode, t_data *f)
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
	else if (keycode == KEY_J || keycode == KEY_K)
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
#include <stdio.h>
int	track_mouse_position(t_data *f)
{
	int	x;
	int	y;

	if (f->set == JULIA)
	{
		mlx_mouse_get_pos(f->init, f->win, &x, &y);
		f->julia_re = f->x_min + ((double)x / WIDTH) * (f->x_max - f->x_min);
		f->julia_im = f->y_min + ((double)y / HEIGHT) * (f->y_max - f->y_min);
		printf("x = %f y = %f\n",f->julia_re, f->julia_im);
		calc_fractal(f);
	}
	return (0);
}
