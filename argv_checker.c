/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:31:41 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/21 18:29:02 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	write_colored(char *color, char *text)
{
	write(1, color, ft_strlen(color));
	write(1, text, ft_strlen(text));
	write(1, RESET, ft_strlen(RESET));
}

static void	print_fractals(void)
{
	write_colored(RED, "\nInvalid Argument!\n");
	write_colored(BLUE, "\nCurrent fractals : ");
	write_colored(GREEN, " Mandelbrot, Julia \n");
	exit(EXIT_FAILURE);
}

static bool	count_check(char *str, int plus_c, int minus_c, int dot_c)
{
	if (plus_c == 0 && minus_c == 0 && dot_c == 0)
		return (true);
	if (plus_c == 1 && minus_c == 0 && dot_c == 0 && str[0] == '+')
		return (true);
	if (plus_c == 0 && minus_c == 1 && dot_c == 0 && str[0] == '-')
		return (true);
	if (plus_c == 0 && minus_c == 0 && dot_c == 1)
	{
		if (str[0] != '.' && str[ft_strlen(str) - 1] != '.')
			return (true);
	}
	if (plus_c == 1 && minus_c == 0 && dot_c == 1 && str[0] == '+')
	{
		if (str[ft_strlen(str) - 1] != '.')
			return (true);
	}
	if (plus_c == 0 && minus_c == 1 && dot_c == 1 && str[0] == '-')
	{
		if (str[ft_strlen(str) - 1] != '.')
			return (true);
	}
	return (false);
}

static bool	digit_check(char *str)
{
	int	i;
	int	plus_c;
	int	minus_c;
	int	dot_c;

	dot_c = 0;
	plus_c = 0;
	minus_c = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '+')
			plus_c++;
		else if (str[i] == '-')
			minus_c++;
		else if (str[i] == '.')
			dot_c++;
		else if (!ft_isdigit(str[i]))
			return (false);
	}
	if (count_check(str, plus_c, minus_c, dot_c) && ft_strlen(str) < 16)
		return (true);
	return (false);
}

void	argv_check(int argc, char **argv)
{
	if (argc < 2)
		print_fractals();
	if (ft_strncmp(argv[1], "Mandelbrot", 10) && argc == 2)
		return ;
	else if (ft_strncmp(argv[1], "Julia", 5))
	{
		if (argc == 2)
			return ;
		if (argc == 4 && digit_check(argv[2]) && digit_check(argv[3]))
			return ;
	}
	print_fractals();
}
