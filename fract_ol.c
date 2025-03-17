/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:20:28 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/17 22:50:11 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void mlx_initializer(t_mlx_data **data, char *set_name)
{
    (*data)->init = mlx_init();
	(*data)->win = mlx_new_window((*data)->init, WIDTH, HEIGHT, set_name);
	(*data)->img = mlx_new_image((*data)->init, WIDTH, HEIGHT);
	(*data)->addr = mlx_get_data_addr((*data)->img, &(*data)->bits_per_pixel, &(*data)->line_length, &(*data)->endian);
}

static void scaling(t_coordinates **coord, double x_min, double x_max, double y_min, double y_max)
{
    double aspect_ratio = (double)WIDTH / (double)HEIGHT;
    double range_x = x_max - x_min;
    double range_y = y_max - y_min;
    double center_x = (x_min + x_max) / 2.0;
    double center_y = (y_min + y_max) / 2.0;
    
    if (aspect_ratio > 1)
	{
        x_min = center_x - (range_x * aspect_ratio) / 2.0;
        x_max = center_x + (range_x * aspect_ratio) / 2.0;
    }
	else if (aspect_ratio < 1)
	{
        y_min = center_y - (range_y / aspect_ratio) / 2.0;
        y_max = center_y + (range_y / aspect_ratio) / 2.0;
    }
    (*coord)->x_min = x_min;
    (*coord)->x_max = x_max;
    (*coord)->y_min = y_min;
    (*coord)->y_max = y_max;
}
static void coordinates_initializer(t_coordinates **coord, char **argv)
{
	if (argv[1][0] == 'M')
	{
		scaling(coord, -2.0, 1.0, -1.5, 1.5);
	}
	else if (argv[1][0] == 'J')
	{
		scaling(coord, -1.5, 1.5, -1.5, 1.5);
	}
	(*coord)->iteration = 300;
}

static void	initializer(t_mlx_data **data, t_coordinates **coord, char **argv)
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
