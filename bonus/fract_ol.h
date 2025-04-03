/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:20:24 by mkulbak           #+#    #+#             */
/*   Updated: 2025/04/01 14:53:58 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

// Define constants for window dimensions and iterations
# define WIDTH 600
# define HEIGHT 600
# define ITERATION 134

// Define fractal types
# define MANDELBROT 1
# define JULIA 2
# define TRICORN 3
# define BURNING_SHIP 4
# define DYNAMIC_JULIA 5

// Define color codes for terminal output
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"

// Include necessary headers
# include "keys.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

// Structure to hold fractal data
typedef struct s_data
{
	void	*init; // Pointer to the MLX initialization
	void	*img; // Pointer to the image
	void	*win; // Pointer to the window
	char	*addr; // Address of the image data
	double	inc; // Increment for iterations
	double	x_min; // Minimum x-coordinate
	double	x_max; // Maximum x-coordinate
	double	y_min; // Minimum y-coordinate
	double	y_max; // Maximum y-coordinate
	double	z_re; // Real part of z
	double	z_im; // Imaginary part of z
	double	c_re; // Real part of c
	double	c_im; // Imaginary part of c
	double	julia_re; // Real part of Julia set
	double	julia_im; // Imaginary part of Julia set
	double	dy_julia_re; // Change in real part of Julia set
	double	dy_julia_im; // Change in imaginary part of Julia set
	double	zoom_factor; // Factor for zooming
	double	move_factor; // Factor for moving
	double	iteration; // Number of iterations for fractal calculation
	int		bits_per_pixel; // Bits per pixel for the image
	int		line_length; // Length of a line in the image
	int		endian; // Endianness of the image
	int		set; // Current fractal set
	int		palette; // Current color palette
	int		palette_code; // Code for the current palette
	bool	gradian; // Flag for gradient coloring
}				t_data;

// Structure to hold range data
typedef struct s_range
{
	double	x_min; // Minimum x-coordinate for the range
	double	x_max; // Maximum x-coordinate for the range
	double	y_min; // Minimum y-coordinate for the range
	double	y_max; // Maximum y-coordinate for the range
}				t_range;

// Function prototypes
void	argv_check(int argc, char **argv);
void	my_mlx_pixel_put(t_data	*data, int x, int y, int color);
void	initializer(t_data *data, char **argv, int argc);
void	calc_fractal(t_data *data);
int		mlx_destroy(t_data *data);
int		key_hook(int keycode, t_data *f);
void	realloc_image(t_data *f);
int		mouse_hook(int keycode, int x, int y, t_data *f);
int		mandel_equation(t_data *f, int x, int y);
int		julia_equation(t_data *f, int x, int y);
int		tricorn_equation(t_data *f, int x, int y);
int		burning_ship_equation(t_data *f, int x, int y);
int		dynamic_julia(t_data *f, int x, int y);
void	change_palette(t_data *f);
void	coordinates_initializer(t_data *f);
void	change_iter(t_data *f, int keycode);
void	change_set(t_data *f, int keycode);
void	move(t_data *f, int keycode);
int		zoom(int keycode, int x, int y, t_data *f);
int		track_mouse_position(t_data *data);
t_range	mandel_scale(void);
t_range	julia_scale(void);
t_range	tricorn_scale(void);
t_range	burning_ship_scale(void);
#endif