/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:31:41 by mkulbak           #+#    #+#             */
/*   Updated: 2025/04/07 20:40:53 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

// Function to print colored error messages to the terminal
static void	write_colored(char *color, char *text)
{
	write(1, color, ft_strlen(color)); // Write color code
	write(1, text, ft_strlen(text)); // Write the text
	write(1, RESET, ft_strlen(RESET)); // Reset color
}

// Function to print available fractal types and exit on invalid argument
static void	print_fractals(void)
{
	write_colored(RED, "\nInvalid Argument!\n"); // Print error message
	write_colored(BLUE, "\nCurrent fractals : "); // Print current fractals message
	write_colored(GREEN, " Mandelbrot, Julia,"); // Print Mandelbrot
	write_colored(GREEN, " Burning Ship, Tricorn, Dynamic Julia\n"); // Print other fractals
	exit(EXIT_FAILURE); // Exit with failure
}

// Function to check the validity of a numeric string
static bool	count_check(char *str, int plus_c, int minus_c, int dot_c)
{
	if (plus_c == 0 && minus_c == 0 && dot_c == 0)
		return (true); // Valid if no signs or dots
	if (plus_c == 1 && minus_c == 0 && dot_c == 0 && str[0] == '+')
		return (true); // Valid if single plus at start
	if (plus_c == 0 && minus_c == 1 && dot_c == 0 && str[0] == '-')
		return (true); // Valid if single minus at start
	if (plus_c == 0 && minus_c == 0 && dot_c == 1)
	{
		if (str[0] != '.' && str[ft_strlen(str) - 1] != '.')
			return (true); // Valid if single dot not at start or end
	}
	if (plus_c == 1 && minus_c == 0 && dot_c == 1 && str[0] == '+')
	{
		if (str[ft_strlen(str) - 1] != '.' && str[1] != '.')
			return (true); // Valid if plus at start and dot not at end
	}
	if (plus_c == 0 && minus_c == 1 && dot_c == 1 && str[0] == '-')
	{
		if (str[ft_strlen(str) - 1] != '.' && str[1] != '.')
			return (true); // Valid if minus at start and dot not at end
	}
	return (false); // Invalid case
}

// Function to check if the string represents a valid number
static bool	digit_check(char *str)
{
	int	i;
	int	plus_c;
	int	minus_c;
	int	dot_c;

	dot_c = 0; // Initialize dot count
	plus_c = 0; // Initialize plus count
	minus_c = 0; // Initialize minus count
	i = -1;
	while (str[++i])
	{
		if (str[i] == '+')
			plus_c++; // Count plus signs
		else if (str[i] == '-')
			minus_c++; // Count minus signs
		else if (str[i] == '.')
			dot_c++; // Count dots
		else if (!ft_isdigit(str[i]))
			return (false); // Return false if non-digit character found
	}
	if (count_check(str, plus_c, minus_c, dot_c) && ft_strlen(str) < 16)
		return (true); // Return true if valid number
	return (false); // Return false if invalid
}

// Function to check command line arguments for fractal program
void	argv_check(int argc, char **argv)
{
	if (argc < 2)
		print_fractals(); // Print available fractals if no arguments
	if (ft_strncmp(argv[1], "Mandelbrot", 10) && ft_strlen(argv[1]) == 10 && argc == 2)
		return ; // Return if Mandelbrot is specified correctly
	if (ft_strncmp(argv[1], "Tricorn", 7) && ft_strlen(argv[1]) == 7 && argc == 2)
		return ; // Return if Tricorn is specified correctly
	if (ft_strncmp(argv[1], "Burning Ship", 12) && ft_strlen(argv[1]) == 12 && argc == 2)
		return ; // Return if Burning Ship is specified correctly
	if (ft_strncmp(argv[1], "Dynamic Julia", 13) && ft_strlen(argv[1]) == 13 && argc == 2)
		return ; // Return if Dynamic Julia is specified correctly
	if (ft_strncmp(argv[1], "Julia", 5) && ft_strlen(argv[1]) == 5)
	{
		if (argc == 2)
			return ; // Return if Julia is specified correctly with 2 arguments
		if (argc == 4 && digit_check(argv[2]) && digit_check(argv[3]))
			return ; // Return if Julia is specified correctly with 4 arguments
	}
	print_fractals(); // Print available fractals if no valid argument found
}
