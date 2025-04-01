/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:59:22 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/31 13:01:41 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	dynamic_julia(t_data *f, int x, int y)
{
	int		iter;
	double	temp_reel;

	iter = 1;
	f->z_re = f->x_min + ((double)x / WIDTH) * (f->x_max - f->x_min);
	f->z_im = f->y_min + ((double)y / HEIGHT) * (f->y_max - f->y_min);
	f->c_re = f->dy_julia_re;
	f->c_im = f->dy_julia_im;
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
