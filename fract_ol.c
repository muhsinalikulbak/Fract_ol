/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:20:28 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/16 13:08:54 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_mlx_pixel_put(t_mlx_data	*data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	mandel_equation(t_coordinates *coord, int x, int y)
{
	int		iteration;
	double	temp_reel;
	//ZOOM yapıldıysa buraya girmeden önce max, min değerleri set edilecek
	iteration = 1;
	coord->z_im = 0;
	coord->z_re = 0;
	coord->c_re = coord->x_min + ((double)x / WIDTH) * (coord->x_max - coord->x_min);
	coord->c_im = coord->y_min + ((double)y / HEIGT) * (coord->y_max - coord->y_min);
	while (iteration <= ITERATION)
	{
		temp_reel = coord->z_re;
		coord->z_re = (coord->z_re * coord->z_re) - (coord->z_im * coord->z_im) + coord->c_re;
		coord->z_im = (2 * temp_reel * coord->z_im ) + coord->c_im;
		if ((coord->z_re * coord->z_re + coord->z_im * coord->z_im) > 4.0)
			return iteration;
		iteration++;
	}
	return iteration;
}

void	mlx_initializer(t_mlx_data **data, char *set_name)
{
	(*data)->init = mlx_init();
	(*data)->win = mlx_new_window((*data)->init, WIDTH, HEIGT, set_name);
	(*data)->img = mlx_new_image((*data)->init, WIDTH, HEIGT);
	(*data)->addr = mlx_get_data_addr((*data)->img, &(*data)->bits_per_pixel, &(*data)->line_length, &(*data)->endian);
}

void	coordinates_initializer(t_coordinates **coord, int set_code)
{
	if (set_code == 'M')
	{
		(*coord)->x_min = -2.0;
		(*coord)->x_max = 1.0;
		(*coord)->y_min = -1.5;
		(*coord)->y_max = 1.5;
	}
	else if (set_code == 'J')
	{
		(*coord)->x_min = -2.0;
		(*coord)->x_max = 2.0;
		(*coord)->y_min = -2.0;
		(*coord)->y_max = 2.0;
	}
}

void	mandelbrot(t_mlx_data **data, t_coordinates **coord)
{
	int	x;
	int	y;
	int	iteration;

	y = 0;
	// Burasi Julia'yı yazdıktan sonra gerekli şeyler ortaksa main init olucak.
	mlx_initializer(data, "Mandelbrot");
	coordinates_initializer(coord, 'M');
	
	while (y < HEIGT)
	{
		x = 0;
		while (x < WIDTH)
		{
			iteration = mandel_equation(*coord, x, y);
			my_mlx_pixel_put(*data, x, y, (iteration * 0xFFFFFF) / ITERATION);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window((*data)->init, (*data)->win, (*data)->img, 0, 0);
}

int	main(int argc, char **argv)
{
	// y satırı temsil eder dikey eksendir
	// x sütunu temsil eder yatay eksendir
	t_mlx_data		*data;
	t_coordinates	*coordinates;

	if (argc < 2)
		return 0; // Burada tüm mevcut setler listelenecek.
	coordinates = malloc(sizeof(t_coordinates));
	data = malloc(sizeof(t_mlx_data));
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
	{
		mandelbrot(&data, &coordinates);
	}
	else if (ft_strncmp(argv[1], "Julia", 5) == 0)
	{
		// Julia için de yapılacak
		mlx_initializer(&data, "Julia");
		coordinates_initializer(&coordinates, 'J');
	}
	mlx_loop(data->init);
}
