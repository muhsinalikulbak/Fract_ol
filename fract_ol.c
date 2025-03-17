/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:20:28 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/17 08:12:32 by mkulbak          ###   ########.fr       */
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
	int		iteration_count;
	double	temp_reel;

	iteration_count = 1;
	coord->z_im = 0;
	coord->z_re = 0;
	coord->c_re = coord->x_min + ((double)x / WIDTH) * (coord->x_max - coord->x_min);
	coord->c_im = coord->y_min + ((double)y / HEIGT) * (coord->y_max - coord->y_min);
	while (iteration_count <= coord->iteration)
	{
		temp_reel = coord->z_re;
		coord->z_re = (coord->z_re * coord->z_re) - (coord->z_im * coord->z_im) + coord->c_re;
		coord->z_im = (2 * temp_reel * coord->z_im ) + coord->c_im;
		if ((coord->z_re * coord->z_re + coord->z_im * coord->z_im) > 4.0)
			return iteration_count;
		iteration_count++;
	}
	return iteration_count;
}

void	mlx_initializer(t_mlx_data **data, char *set_name)
{
	(*data)->init = mlx_init();
	(*data)->win = mlx_new_window((*data)->init, WIDTH, HEIGT, set_name);
	(*data)->img = mlx_new_image((*data)->init, WIDTH, HEIGT);
	(*data)->addr = mlx_get_data_addr((*data)->img, &(*data)->bits_per_pixel, &(*data)->line_length, &(*data)->endian);
}

void	coordinates_initializer(t_coordinates **coord, char **argv)
{
	(*coord)->iteration = 300;
	if (argv[1][0] == 'M')
	{
		(*coord)->x_min = -2.0;
		(*coord)->x_max = 1.0;
		(*coord)->y_min = -1.5;
		(*coord)->y_max = 1.5;
	}
	else if (argv[1][0] == 'J')
	{
		(*coord)->x_min = -2.0;
		(*coord)->x_max = 2.0;
		(*coord)->y_min = -2.0;
		(*coord)->y_max = 2.0;
	}
}

void	calc_pixel(t_mlx_data **data, t_coordinates **coord)
{
	int		x;
	int		y;
	double	iteration_count;

	y = 0;
	while (y < HEIGT)
	{
		x = 0;
		while (x < WIDTH)
		{
			iteration_count = mandel_equation(*coord, x, y);
			my_mlx_pixel_put(*data, x, y, (iteration_count * 0xFFFFFF) / (*coord)->iteration);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window((*data)->init, (*data)->win, (*data)->img, 0, 0);
}

void	write_colored(char *color, char *text) 
{
    write(1, color, ft_strlen(color));
    write(1, text, ft_strlen(text));
    write(1, RESET, ft_strlen(RESET));
}

void	print_fractals()
{
	write_colored(RED, "\nInvalid Argument!\n");
	write_colored(BLUE, "\nCurrent fractals : ");
	write_colored(GREEN, " Mandelbrot, Julia \n");
}

void	argv_check(int argc, char **argv)
{
	if (argc < 2)
	{
		print_fractals();
		exit(EXIT_FAILURE);
	}
	// else if (ft_strncmp(argv[1], "Julia", 5) )
}

void	initializer(t_mlx_data **data, t_coordinates **coord, char **argv)
{
	mlx_initializer(data, argv[1]);
	coordinates_initializer(coord, argv);
}

int	main(int argc, char **argv)
{
	// y satırı temsil eder dikey eksendir
	// x sütunu temsil eder yatay eksendir
	t_mlx_data		*data;
	t_coordinates	*coordinates;

	argv_check(argc, argv);
	coordinates = malloc(sizeof(t_coordinates));
	data = malloc(sizeof(t_mlx_data));
	initializer(&data, &coordinates, argv);
	calc_pixel(&data, &coordinates);

	mlx_loop(data->init);
}
