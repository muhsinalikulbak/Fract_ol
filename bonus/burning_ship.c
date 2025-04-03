/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:35:27 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/26 01:13:17 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

// Function to calculate the absolute value of a number
static double	abs_value(double num)
{
	if (num >= 0.0)
		return (num); // Return the number if it's non-negative
	if (num < 0.0)
		return (-num); // Return the negation if the number is negative
	return (num); // Return the number (should not reach here)
}

// Function to calculate the Burning Ship fractal equation for a given pixel
int	burning_ship_equation(t_data *f, int x, int y)
{
	int		iter; // Iteration counter
	double	temp_reel; // Temporary variable for real part

	iter = 1; // Initialize iteration count
	f->z_re = 0; // Initialize real part of z
	f->z_im = 0; // Initialize imaginary part of z
	f->c_re = f->x_min + ((double)x / WIDTH) * (f->x_max - f->x_min); // Calculate real part of c
	f->c_im = f->y_min + ((double)y / HEIGHT) * (f->y_max - f->y_min); // Calculate imaginary part of c
	
	// Iterate to determine if the point escapes to infinity
	while (iter <= f->iteration)
	{
		f->z_re = abs_value(f->z_re); // Use absolute value for real part
		f->z_im = abs_value(f->z_im); // Use absolute value for imaginary part
		temp_reel = f->z_re; // Store the current real part
		f->z_re = (f->z_re * f->z_re) - (f->z_im * f->z_im) + f->c_re; // Update real part
		f->z_im = (2 * temp_reel * f->z_im) + f->c_im; // Update imaginary part
		if ((f->z_re * f->z_re + f->z_im * f->z_im) > 4.0) // Check for escape condition
			return (iter); // Return the number of iterations before escape
		iter++; // Increment iteration count
	}
	return (iter); // Return the maximum iteration count if not escaped
}
