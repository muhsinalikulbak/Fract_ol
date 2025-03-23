/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:55:15 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/23 03:52:30 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	realloc_image(t_data *f)
{
	mlx_destroy_image(f->init, f->img);
	f->img = mlx_new_image(f->init, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(
			f->img, &f->bits_per_pixel, &f->line_length, &f->endian);
}

int	mlx_destroy(t_data *data)
{
	mlx_destroy_image(data->init, data->img);
	mlx_destroy_window(data->init, data->win);
	mlx_destroy_display(data->init);
	free(data->init);
	free(data);
	exit(EXIT_SUCCESS);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
