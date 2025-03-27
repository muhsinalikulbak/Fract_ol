/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:18:30 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/27 04:00:19 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

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
