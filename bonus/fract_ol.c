/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:20:28 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/31 15:40:25 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

// Main function to start the fractal application
int	main(int argc, char **argv)
{
	t_data	*data; // Pointer to fractal data

	argv_check(argc, argv); // Check command line arguments
	data = malloc(sizeof(t_data)); // Allocate memory for fractal data
	initializer(data, argv, argc); // Initialize fractal data and MLX
	calc_fractal(data); // Calculate the fractal based on the selected type
	mlx_hook(data->win, EVENT_CLOSE_BTN, 1L << 17, mlx_destroy, data); // Set up close button event
	mlx_key_hook(data->win, key_hook, data); // Set up key event handling
	mlx_mouse_hook(data->win, mouse_hook, data); // Set up mouse event handling
	mlx_loop(data->init); // Start the MLX event loop
}
