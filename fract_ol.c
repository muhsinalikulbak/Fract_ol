/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:20:28 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/19 02:07:25 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int argc, char **argv)
{
	t_mlx_data		*data;
	t_coordinates	*coordinates;
	// y satırı temsil eder dikey eksendir
	// x sütunu temsil eder yatay eksendir
	argv_check(argc, argv);
	coordinates = malloc(sizeof(t_coordinates));
	data = malloc(sizeof(t_mlx_data));
	initializer(data, coordinates, argv);
	calc_pixel(data, coordinates);
	mlx_loop(data->init);
}
