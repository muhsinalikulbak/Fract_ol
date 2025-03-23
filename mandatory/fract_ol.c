/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:20:28 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/23 03:58:09 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	argv_check(argc, argv);
	data = malloc(sizeof(t_data));
	initializer(data, argv, argc);
	calc_fractal(data);
	mlx_hook(data->win, EVENT_CLOSE_BTN, 1L << 17, mlx_destroy, data);
	mlx_key_hook(data->win, key_event, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_loop(data->init);
}
