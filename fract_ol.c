/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:20:28 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/19 01:17:29 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int argc, char **argv)
{
	// y satırı temsil eder dikey eksendir
	// x sütunu temsil eder yatay eksendir
	t_mlx_data		*data;
	t_coordinates	*coordinates;

	argv_check(argc, argv);
	coordinates = malloc(sizeof(t_coordinates));
	data = malloc(sizeof(t_mlx_data));
	initializer(data, coordinates, argv);
	calc_pixel(data, coordinates);
	mlx_loop(data->init);
}
