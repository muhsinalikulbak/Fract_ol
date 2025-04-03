/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:55:15 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/23 03:52:30 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

// Function to reallocate the image in the MLX context
void	realloc_image(t_data *f)
{
	mlx_destroy_image(f->init, f->img); // Destroy the old image
	f->img = mlx_new_image(f->init, WIDTH, HEIGHT); // Create a new image
	f->addr = mlx_get_data_addr(
			f->img, &f->bits_per_pixel, &f->line_length, &f->endian); // Get the address of the new image data
}

// Function to clean up and destroy the MLX context and free resources
int	mlx_destroy(t_data *data)
{
	mlx_destroy_image(data->init, data->img); // Destroy the image
	mlx_destroy_window(data->init, data->win); // Destroy the window
	mlx_destroy_display(data->init); // Destroy the display
	free(data->init); // Free the MLX initialization
	free(data); // Free the fractal data
	exit(EXIT_SUCCESS); // Exit the program
}

// Function to put a pixel on the image at specified coordinates with a given color
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)); // Calculate the pixel's address
	*(unsigned int *)dst = color; // Set the pixel color
}
