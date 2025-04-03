/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:47:20 by mkulbak           #+#    #+#             */
/*   Updated: 2025/04/01 14:55:57 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <stdio.h>

// Function to handle keyboard input events
int	key_hook(int keycode, t_data *f)
{
	if (keycode == KEY_ESC) // If the escape key is pressed
		mlx_destroy(f); // Destroy the MLX context and exit
	else if (keycode == KEY_SPACE) // If the space key is pressed
		change_palette(f); // Change the color palette
	else if (keycode >= KEY_ONE && keycode <= KEY_FIVE) // If number keys are pressed
		change_set(f, keycode); // Change the fractal set
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || keycode == KEY_D) // Movement keys
		move(f, keycode); // Move the fractal view
	else if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_RIGHT || keycode == KEY_LEFT) // Arrow keys
		move(f, keycode); // Move the fractal view
	else if (keycode == KEY_J || keycode == KEY_K) // Keys to change iterations
	{
		change_iter(f, keycode); // Change the iteration count
		return (0);
	}
	else if (keycode == KEY_G) // If G key is pressed
	{
		f->gradian = !f->gradian; // Toggle gradient flag
	}
	else
		return (0); // Return if no valid key is pressed
	calc_fractal(f); // Recalculate the fractal
	return (0); // Return success
}

// Function to handle mouse input events
int	mouse_hook(int keycode, int x, int y, t_data *f)
{
	int	key;

	key = zoom(keycode, x, y, f); // Handle zooming based on mouse input
	if (key == EXIT_SUCCESS) // If zooming was successful
		calc_fractal(f); // Recalculate the fractal
	return (0); // Return success
}

// Function to track mouse position for dynamic Julia set
int	track_mouse_position(t_data *f)
{
	int	x; // Mouse x-coordinate
	int	y; // Mouse y-coordinate

	if (f->set == DYNAMIC_JULIA) // If the current set is Dynamic Julia
	{
		mlx_mouse_get_pos(f->init, f->win, &x, &y); // Get the mouse position
		f->dy_julia_re = f->x_min + ((double)x / WIDTH) * (f->x_max - f->x_min); // Update real part of Julia set
		f->dy_julia_im = f->y_min + ((double)y / HEIGHT) * (f->y_max - f->y_min); // Update imaginary part of Julia set
		printf("x = %f y = %f\n", f->dy_julia_re, f->dy_julia_im); // Print mouse position
		calc_fractal(f); // Recalculate the fractal
	}
	return (0); // Return success
}
