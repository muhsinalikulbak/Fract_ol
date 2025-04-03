/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:55:41 by mkulbak           #+#    #+#             */
/*   Updated: 2025/04/01 14:56:26 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

// Function to calculate the pixel values for the fractal based on the selected type
static void	calc_pixel(t_data *f, int (*equation)(t_data*, int, int))
{
	int		x; // X-coordinate
	int		y; // Y-coordinate
	double	iter; // Iteration count

	if (f->img)
		realloc_image(f); // Reallocate the image if it exists
	f->iteration += f->inc; // Adjust the iteration count based on increment
	y = 0; // Initialize y-coordinate
	while (y < HEIGHT) // Loop through each pixel row
	{
		x = 0; // Initialize x-coordinate
		while (x < WIDTH) // Loop through each pixel column
		{
			iter = equation(f, x, y); // Calculate the fractal value for the pixel
			if (f->gradian)
				my_mlx_pixel_put(f, x, y, (iter * f->palette / f->iteration)); // Set pixel color with gradient
			else
				my_mlx_pixel_put(f, x, y, (iter * f->palette)); // Set pixel color without gradient
			x++; // Move to the next pixel in the row
		}
		y++; // Move to the next row
	}
	mlx_put_image_to_window(f->init, f->win, f->img, 0, 0); // Display the image in the window
}

// Function to calculate the fractal based on the selected type
void	calc_fractal(t_data *f)
{
	if (f->set == MANDELBROT)
		calc_pixel(f, mandel_equation); // Calculate Mandelbrot fractal
	else if (f->set == JULIA)
		calc_pixel(f, julia_equation); // Calculate Julia fractal
	else if (f->set == TRICORN)
		calc_pixel(f, tricorn_equation); // Calculate Tricorn fractal
	else if (f->set == BURNING_SHIP)
		calc_pixel(f, burning_ship_equation); // Calculate Burning Ship fractal
	else if (f->set == DYNAMIC_JULIA)
		calc_pixel(f, dynamic_julia); // Calculate Dynamic Julia fractal
}
