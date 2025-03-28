/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 04:09:38 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/28 16:15:53 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	palette(t_data *f)
{
	f->palette_code++;
	if (f->palette_code == 2)
		f->palette = 0xEFCAE0;  // Pastel yeşil
	else if (f->palette_code == 3)
		f->palette = 0xAA5500;  // Kiremit kırmızısı
	else if (f->palette_code == 4)
		f->palette = 0xFFFFFF;  // Beyaz
	else if (f->palette_code == 5)
		f->palette = 0x00AFAF;  // Turkuaz
	else if (f->palette_code == 6)
		f->palette = 0x5555FF;  // Açık mavi
	else if (f->palette_code == 7)
		f->palette = 0xEA00EA;  // Parlak mor
	else if (f->palette_code == 8)
		f->palette = 0xABCDE0;  // Açık mavi-yeşil
	else if (f->palette_code == 9)
		f->palette = 0xFCD000;  // Altın sarısı
	else
	{
		f->palette = 0xFF0000;  // Parlak kırmızı
		f->palette_code = 1;
	}
}
