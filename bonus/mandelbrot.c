/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:56:28 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/26 03:28:09 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mandel_equation(t_data *f, int x, int y)
{
	int		iter;
	double	temp_reel;

	iter = 1;
	f->z_re = 0;
	f->z_im = 0;
	f->c_re = f->x_min + ((double)x / WIDTH) * (f->x_max - f->x_min);
	f->c_im = f->y_min + ((double)y / HEIGHT) * (f->y_max - f->y_min);
	while (iter <= f->iteration)
	{
		temp_reel = f->z_re;
		f->z_re = (
				f->z_re * f->z_re) - (f->z_im * f->z_im) + f->c_re;
		f->z_im = (2 * temp_reel * f->z_im) + f->c_im;
		if ((f->z_re * f->z_re + f->z_im * f->z_im) > 4.0)
			return (iter);
		iter++;
	}
	return (iter);
}
