/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 04:09:38 by mkulbak           #+#    #+#             */
/*   Updated: 2025/04/01 02:52:22 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

// Function to change the current fractal set based on key input
void	change_set(t_data *f, int keycode)
{
	if (keycode == KEY_ONE) // If 1 key is pressed
	{
		f->set = MANDELBROT; // Set to Mandelbrot
		coordinates_initializer(f); // Initialize coordinates for Mandelbrot
	}
	else if (keycode == KEY_TWO) // If 2 key is pressed
	{
		f->set = JULIA; // Set to Julia
		coordinates_initializer(f); // Initialize coordinates for Julia
	}
	else if (keycode == KEY_THREE) // If 3 key is pressed
	{
		f->set = TRICORN; // Set to Tricorn
		coordinates_initializer(f); // Initialize coordinates for Tricorn
	}
	else if (keycode == KEY_FOUR) // If 4 key is pressed
	{
		f->set = BURNING_SHIP; // Set to Burning Ship
		coordinates_initializer(f); // Initialize coordinates for Burning Ship
	}
	else if (keycode == KEY_FIVE) // If 5 key is pressed
	{
		f->set = DYNAMIC_JULIA; // Set to Dynamic Julia
		coordinates_initializer(f); // Initialize coordinates for Dynamic Julia
	}
}

// Function to change the color palette based on user input
void	change_palette(t_data *f)
{
	f->palette_code++; // Increment palette code
	if (f->palette_code == 2)
		f->palette = 0xFFB300; // Set to a new color
	else if (f->palette_code == 3)
		f->palette = 0xFF9F1C; // Set to another color
	else if (f->palette_code == 4)
		f->palette = 0xFFD23F; // Set to another color
	else if (f->palette_code == 5)
		f->palette = 0xFFF3B0; // Set to another color
	else if (f->palette_code == 6)
		f->palette = 0xFEFEBA; // Set to another color
	else if (f->palette_code == 7)
		f->palette = 0xFFD166; // Set to another color
	else if (f->palette_code == 8)
		f->palette = 0xE3F2FD; // Set to another color
	else if (f->palette_code == 9)
		f->palette = 0x4DD0E1; // Set to another color
	else if (f->palette_code == 10)
		f->palette = 0xFF0000; // Set to another color
	else if (f->palette_code == 11) // If palette code exceeds limit
	{
		f->palette_code = 1; // Reset palette code
		f->palette = 0xE0F7FA; // Set to default color
	}
}

// Function to change the iteration count based on user input
void	change_iter(t_data *f, int keycode)
{
	if (keycode == KEY_J) // If J key is pressed
		f->inc = 1; // Set increment to 1
	else if (keycode == KEY_K) // If K key is pressed
	{
		if (f->inc == 0) // If increment is already 0
			return; // Do nothing
		f->inc = 0; // Reset increment
		f->iteration = ITERATION; // Reset iteration count to default
	}
	calc_fractal(f); // Recalculate the fractal
}
