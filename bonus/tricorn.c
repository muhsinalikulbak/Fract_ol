/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:40:54 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/24 19:41:18 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

// Function to calculate the Tricorn fractal equation for a given pixel
int	tricorn_equation(t_data *f, int x, int y)
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
		temp_reel = f->z_re; // Store the current real part
		f->z_re = (f->z_re * f->z_re) - (f->z_im * f->z_im) + f->c_re; // Update real part
		f->z_im = (-2 * temp_reel * f->z_im) + f->c_im; // Update imaginary part
		if ((f->z_re * f->z_re + f->z_im * f->z_im) > 4.0) // Check for escape condition
			return (iter); // Return the number of iterations before escape
		iter++; // Increment iteration count
	}
	return (iter); // Return the maximum iteration count if not escaped
}
