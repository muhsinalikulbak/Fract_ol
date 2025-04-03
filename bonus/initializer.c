/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:51:55 by mkulbak           #+#    #+#             */
/*   Updated: 2025/04/04 02:08:56 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

// Function to initialize the MLX library and create a new window
static void	mlx_initializer(t_data *mlx, char *set_name)
{
	mlx->init = mlx_init(); // Initialize MLX
	mlx->win = mlx_new_window(mlx->init, WIDTH, HEIGHT, set_name); // Create a new window
	mlx->img = mlx_new_image(mlx->init, WIDTH, HEIGHT); // Create a new image
	mlx->addr = mlx_get_data_addr(mlx->img,
			&mlx->bits_per_pixel, &mlx->line_length, &mlx->endian); // Get the address of the image data
}

// Function to scale the fractal view based on the aspect ratio
static void	scaling(t_data *f, t_range scale)
{
	double	aspect_ratio;
	double	range_x;
	double	range_y;
	double	center_x;
	double	center_y;

	aspect_ratio = (double)WIDTH / (double)HEIGHT; // Calculate aspect ratio
	range_x = scale.x_max - scale.x_min; // Calculate range in x-direction
	range_y = scale.y_max - scale.y_min; // Calculate range in y-direction
	center_x = (scale.x_min + scale.x_max) / 2.0; // Calculate center x-coordinate
	center_y = (scale.y_min + scale.y_max) / 2.0; // Calculate center y-coordinate
	
	// Adjust the x-range based on the aspect ratio
	if (aspect_ratio > 1)
	{
		scale.x_min = center_x - (range_x * aspect_ratio) / 2.0;
		scale.x_max = center_x + (range_x * aspect_ratio) / 2.0;
	}
	// Adjust the y-range based on the aspect ratio
	else if (aspect_ratio < 1)
	{
		scale.y_min = center_y - (range_y / aspect_ratio) / 2.0;
		scale.y_max = center_y + (range_y / aspect_ratio) / 2.0;
	}
	f->x_min = scale.x_min; // Set the minimum x-coordinate
	f->x_max = scale.x_max; // Set the maximum x-coordinate
	f->y_min = scale.y_min; // Set the minimum y-coordinate
	f->y_max = scale.y_max; // Set the maximum y-coordinate
}

// Function to initialize the coordinates based on the selected fractal set
void	coordinates_initializer(t_data *f)
{
	if (f->set == MANDELBROT)
		scaling(f, mandel_scale()); // Scale for Mandelbrot set
	else if (f->set == TRICORN)
		scaling(f, tricorn_scale()); // Scale for Tricorn set
	else if (f->set == BURNING_SHIP)
		scaling(f, burning_ship_scale()); // Scale for Burning Ship set
	else if (f->set == JULIA || f->set == DYNAMIC_JULIA)
	{
		scaling(f, julia_scale()); // Scale for Julia set
		if (f->set == DYNAMIC_JULIA)
		{
			mlx_loop_hook(f->init, track_mouse_position, f); // Set up mouse tracking for dynamic Julia
		}
	}
}

// Function to set the fractal type based on the input string
static void	set_name_initalize(t_data *f, char *set)
{
	if (ft_strncmp(set, "Mandelbrot", 10))
		f->set = MANDELBROT; // Set to Mandelbrot
	else if (ft_strncmp(set, "Julia", 5))
		f->set = JULIA; // Set to Julia
	else if (ft_strncmp(set, "Tricorn", 7))
		f->set = TRICORN; // Set to Tricorn
	else if (ft_strncmp(set, "Burning Ship", 12))
		f->set = BURNING_SHIP; // Set to Burning Ship
	else if (ft_strncmp(set, "Dynamic Julia", 13))
		f->set = DYNAMIC_JULIA; // Set to Dynamic Julia
}

// Main initializer function to set up the fractal data
void	initializer(t_data *f, char **argv, int argc)
{
	mlx_initializer(f, argv[1]); // Initialize MLX and create window
	set_name_initalize(f, argv[1]); // Set the fractal type
	if (argc == 4)
	{
		f->julia_re = ft_atod(argv[2]); // Set Julia real part from argument
		f->julia_im = ft_atod(argv[3]); // Set Julia imaginary part from argument
	}
	else if (argc == 2)
	{
		f->julia_re = -0.8; // Default value for Julia real part
		f->julia_im = 0.156; // Default value for Julia imaginary part
	}
	coordinates_initializer(f); // Initialize coordinates based on the fractal set
	f->inc = 0.0; // Initialize increment
	f->iteration = ITERATION; // Set the number of iterations
	f->zoom_factor = 0.198567856; // Set the zoom factor
	f->move_factor = 0.2; // Set the move factor
	f->palette_code = 1; // Initialize palette code
	f->palette = 0xE0F7FA; // Set default palette color
	f->gradian = false; // Initialize gradient flag
}
