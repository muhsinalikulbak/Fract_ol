/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 04:09:38 by mkulbak           #+#    #+#             */
/*   Updated: 2025/04/01 02:52:22 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	change_set(t_data *f, int keycode)
{
	if (keycode == KEY_ONE)
	{
		f->set = MANDELBROT;
		coordinates_initializer(f);
	}
	else if (keycode == KEY_TWO)
	{
		f->set = JULIA;
		coordinates_initializer(f);
	}
	else if (keycode == KEY_THREE)
	{
		f->set = TRICORN;
		coordinates_initializer(f);
	}
	else if (keycode == KEY_FOUR)
	{
		f->set = BURNING_SHIP;
		coordinates_initializer(f);
	}
	else if (keycode == KEY_FIVE)
	{
		f->set = DYNAMIC_JULIA;
		coordinates_initializer(f);
	}
}

void	change_palette(t_data *f)
{
	f->palette_code++;
	if (f->palette_code == 2)
		f->palette = 0xFFB300;
	else if (f->palette_code == 3)
		f->palette = 0xFF9F1C;
	else if (f->palette_code == 4)
		f->palette = 0xFFD23F;
	else if (f->palette_code == 5)
		f->palette = 0xFFF3B0;
	else if (f->palette_code == 6)
		f->palette = 0xFEFEBA;
	else if (f->palette_code == 7)
		f->palette = 0xFFD166;
	else if (f->palette_code == 8)
		f->palette = 0xE3F2FD;
	else if (f->palette_code == 9)
		f->palette = 0x4DD0E1;
	else if (f->palette_code == 10)
		f->palette = 0xFF0000;
	else if (f->palette_code == 11)
	{
		f->palette_code = 1;
		f->palette = 0xE0F7FA;
	}
}

void	change_iter(t_data *f, int keycode)
{
	if (keycode == KEY_J)
		f->inc = 1;
	else if (keycode == KEY_K)
	{
		if (f->inc == 0)
			return ;
		f->inc = 0;
		f->iteration = ITERATION;
	}
	calc_fractal(f);
}
