/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 04:09:38 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/27 04:03:01 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	palette(t_data *f)
{
	f->palette_code++;
	if (f->palette_code == 2)
		f->palette = 0xEFCAE * 255;
	else if (f->palette_code == 3)
		f->palette = 0xAAAAA * 588;
	else if (f->palette_code == 4)
		f->palette = 0xFFFFF * 255;
	else if (f->palette_code == 5)
		f->palette = 0xEAFAE * 255;
	else if (f->palette_code == 6)
		f->palette = 0xAAAFE * 255;
	else if (f->palette_code == 7)
		f->palette = 0xEAFAE * 255;
	else if (f->palette_code == 8)
		f->palette = 0xABCDE * 255;
	else if (f->palette_code == 9)
		f->palette = 0xFCDAF * 255;
	else if (f->palette_code == 9)
		f->palette = 0xFFEAA * 255;
	else
	{
		f->palette = 0xEFCAE;
		f->palette_code = 1;
	}
}
