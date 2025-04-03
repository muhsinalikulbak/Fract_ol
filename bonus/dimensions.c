/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:20:38 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/24 23:16:25 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

// Function to define the scaling range for the Mandelbrot set
t_range	mandel_scale(void)
{
	t_range	range;

	range.x_min = -2.0; // Minimum x-coordinate for Mandelbrot
	range.x_max = 1.0; // Maximum x-coordinate for Mandelbrot
	range.y_min = -1.5; // Minimum y-coordinate for Mandelbrot
	range.y_max = 1.5; // Maximum y-coordinate for Mandelbrot
	return (range); // Return the defined range
}

// Function to define the scaling range for the Julia set
t_range	julia_scale(void)
{
	t_range	range;

	range.x_min = -1.5; // Minimum x-coordinate for Julia
	range.x_max = 1.5; // Maximum x-coordinate for Julia
	range.y_min = -1.5; // Minimum y-coordinate for Julia
	range.y_max = 1.5; // Maximum y-coordinate for Julia
	return (range); // Return the defined range
}

// Function to define the scaling range for the Tricorn set
t_range	tricorn_scale(void)
{
	t_range	range;

	range.x_min = -2.0; // Minimum x-coordinate for Tricorn
	range.x_max = 2.0; // Maximum x-coordinate for Tricorn
	range.y_min = -2.0; // Minimum y-coordinate for Tricorn
	range.y_max = 2.0; // Maximum y-coordinate for Tricorn
	return (range); // Return the defined range
}

// Function to define the scaling range for the Burning Ship set
t_range	burning_ship_scale(void)
{
	t_range	range;

	range.x_min = -2.0; // Minimum x-coordinate for Burning Ship
	range.x_max = 1.5; // Maximum x-coordinate for Burning Ship
	range.y_min = -1.8; // Minimum y-coordinate for Burning Ship
	range.y_max = 1.8; // Maximum y-coordinate for Burning Ship
	return (range); // Return the defined range
}
