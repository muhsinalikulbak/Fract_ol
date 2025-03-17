/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:20:24 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/17 07:49:21 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# define WIDTH 860
# define HEIGT 860
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"
# include "minilibx-linux/mlx.h"
# include  "libft/libft.h"
# include <stdio.h>
# include <math.h>

typedef struct	s_data
{
	void	*init;
	void	*img;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx_data;

typedef struct s_coordinates
{
	double	iteration;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	z_re;
	double	z_im;
	double	c_re;
	double	c_im;
}				t_coordinates;


#endif