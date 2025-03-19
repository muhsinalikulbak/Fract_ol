/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:11:36 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/19 23:59:01 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	decimal_part(int i, double res, const char *str)
{
	double	decimal_factor;

	decimal_factor = 0.1;
	if (str[i] != '\0')
	{
		while (ft_isdigit(str[i]))
			i++;
		while (str[i])
		{
			res += (str[i] - '0') * decimal_factor;
			decimal_factor *= 0.1;
			i++;
		}
	}
	return (res);
}

double	ft_atob(const char *str)
{
	int		i;
	double	res;
	double	sign;

	sign = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (decimal_part(i, res, str) * sign);
}
