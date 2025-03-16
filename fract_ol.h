/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:20:24 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/16 13:08:25 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# define ITERATION 1000
# define WIDTH 1920
# define HEIGT 1080

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