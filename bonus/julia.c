/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:56:03 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/23 16:57:39 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	julia_equation(t_data *f, int x, int y)
{
	int		iter;
	double	temp_reel;

	iter = 1;
	f->z_re = f->x_min + ((double)x / WIDTH) * (f->x_max - f->x_min);
	f->z_im = f->y_min + ((double)y / HEIGHT) * (f->y_max - f->y_min);
	f->c_re = f->julia_re;
	f->c_im = f->julia_im;
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
