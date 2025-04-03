/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:56:03 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/23 16:57:39 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

// Function to calculate the Julia fractal equation for a given pixel
int	julia_equation(t_data *f, int x, int y)
{
	int		iter; // Iteration counter
	double	temp_reel; // Temporary variable for real part

	iter = 1; // Initialize iteration count
	f->z_re = f->x_min + ((double)x / WIDTH) * (f->x_max - f->x_min); // Calculate real part of z
	f->z_im = f->y_min + ((double)y / HEIGHT) * (f->y_max - f->y_min); // Calculate imaginary part of z
	f->c_re = f->julia_re; // Set real part of c for Julia set
	f->c_im = f->julia_im; // Set imaginary part of c for Julia set
	
	// Iterate to determine if the point escapes to infinity
	while (iter <= f->iteration)
	{
		temp_reel = f->z_re; // Store the current real part
		f->z_re = (f->z_re * f->z_re) - (f->z_im * f->z_im) + f->c_re; // Update real part
		f->z_im = (2 * temp_reel * f->z_im) + f->c_im; // Update imaginary part
		if ((f->z_re * f->z_re + f->z_im * f->z_im) > 4.0) // Check for escape condition
			return (iter); // Return the number of iterations before escape
		iter++; // Increment iteration count
	}
	return (iter); // Return the maximum iteration count if not escaped
}
