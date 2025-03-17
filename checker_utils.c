/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:31:41 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/17 14:35:09 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	write_colored(char *color, char *text) 
{
	write(1, color, ft_strlen(color));
	write(1, text, ft_strlen(text));
	write(1, RESET, ft_strlen(RESET));
}

static void	print_fractals()
{
	write_colored(RED, "\nInvalid Argument!\n");
	write_colored(BLUE, "\nCurrent fractals : ");
	write_colored(GREEN, " Mandelbrot, Julia \n");
}

void	argv_check(int argc, char **argv)
{
	if (argc < 2)
	{
		print_fractals();
		exit(EXIT_FAILURE);
	}
	// else if (ft_strncmp(argv[1], "Julia", 5) )
}
