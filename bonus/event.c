/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 03:00:00 by mkulbak           #+#    #+#             */
/*   Updated: 2025/04/01 02:56:29 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	zoom(int keycode, int x, int y, t_data *f)
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
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	move(t_data *f, int keycode)
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
