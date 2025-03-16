/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:20:28 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/16 03:15:17 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	mandel_equation(int z_reel, int z_imag, int c_reel, int c_imag)
{
	int	iteration;

	iteration = 0;
	z_reel = 0;
	z_imag = 0;
}

int	main(void)
{
	t_data	data;

	data.init = mlx_init();
	data.win = mlx_new_window(data.init, WIDTH, HEIGT, "Mandelbrot");
	data.img = mlx_new_image(data.init, WIDTH, HEIGT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	
	




	mlx_loop(data.init);
}
