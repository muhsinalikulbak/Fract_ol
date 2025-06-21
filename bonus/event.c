/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 03:00:00 by mkulbak           #+#    #+#             */
/*   Updated: 2025/04/01 02:56:29 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

// Function to handle zooming in and out based on mouse position and key input
int	zoom(int keycode, int x, int y, t_data *f)
{
	double	mouse_x;
	double	mouse_y;

	// Calculate the real coordinates of the mouse position
	mouse_x = f->x_min + ((double)x / WIDTH) * (f->x_max - f->x_min);
	mouse_y = f->y_min + ((double)y / HEIGHT) * (f->y_max - f->y_min);
	
	// Zoom in if the scroll up key is pressed
	if (keycode == SCROOL_UP)
	{
		f->x_min -= (f->x_min - mouse_x) * f->zoom_factor;
		f->x_max -= (f->x_max - mouse_x) * f->zoom_factor;
		f->y_min -= (f->y_min - mouse_y) * f->zoom_factor;
		f->y_max -= (f->y_max - mouse_y) * f->zoom_factor;
	}
	// Zoom out if the scroll down key is pressed
	else if (keycode == SCROOL_DOWN)
	{
		f->x_min += (f->x_min - mouse_x) * f->zoom_factor;
		f->x_max += (f->x_max - mouse_x) * f->zoom_factor;
		f->y_min += (f->y_min - mouse_y) * f->zoom_factor;
		f->y_max += (f->y_max - mouse_y) * f->zoom_factor;
	}
	else
		return (EXIT_FAILURE); // Return failure if no valid key is pressed
	return (EXIT_SUCCESS); // Return success if zooming is performed
}

// Function to move the fractal view based on key input
void	move(t_data *f, int keycode)
{
	double	range_x;
	double	range_y;

	// Calculate the current range of the fractal view
	range_x = f->x_max - f->x_min;
	range_y = f->y_max - f->y_min;
	
	// Move up or down based on the key pressed
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		f->y_max -= range_y * f->move_factor; // Move the view up
		f->y_min -= range_y * f->move_factor; // Move the view up
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		f->y_max += range_y * f->move_factor; // Move the view down
		f->y_min += range_y * f->move_factor; // Move the view down
	}
	// Move left or right based on the key pressed
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		f->x_max -= range_x * f->move_factor; // Move the view left
		f->x_min -= range_x * f->move_factor; // Move the view left
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		f->x_max += range_x * f->move_factor; // Move the view right
		f->x_min += range_x * f->move_factor; // Move the view right
	}
}

// Function to handle expose events (window redraw)
int	expose_event(t_data *f)
{
	calc_fractal(f);
	return (0);
}
