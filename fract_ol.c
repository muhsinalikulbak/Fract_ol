/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:20:28 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/17 15:01:02 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void mlx_initializer(t_mlx_data **data, char *set_name)
{
    (*data)->init = mlx_init();
	(*data)->win = mlx_new_window((*data)->init, WIDTH, HEIGT, set_name);
	(*data)->img = mlx_new_image((*data)->init, WIDTH, HEIGT);
	(*data)->addr = mlx_get_data_addr((*data)->img, &(*data)->bits_per_pixel, &(*data)->line_length, &(*data)->endian);
}

static void coordinates_initializer(t_coordinates **coord, char **argv)
{
    (*coord)->iteration = 100;
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
