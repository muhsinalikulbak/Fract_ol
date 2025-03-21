/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:20:28 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/21 06:50:14 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	close_window(int keycode, t_data *data)
{

	mlx_destroy_image(data->init, data->img);
	mlx_destroy_window(data->init, data->win);
	mlx_destroy_display(data->init);
	free(data->init);
	free(data);
	exit (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	// y satırı temsil eder dikey eksendir
	// x sütunu temsil eder yatay eksendir
	argv_check(argc, argv);
	data = malloc(sizeof(t_data));
	initializer(data, argv);
	calc_fractal(data);

	mlx_hook(data->win, 2, 1L << 0, close_window, data);
	mlx_loop(data->init);

}
