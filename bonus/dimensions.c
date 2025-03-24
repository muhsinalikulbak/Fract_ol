/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:20:38 by mkulbak           #+#    #+#             */
/*   Updated: 2025/03/24 23:16:25 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_range	mandel_scale(void)
{
	t_range	range;

	range.x_min = -2.0;
	range.x_max = 1.0;
	range.y_min = -1.5;
	range.y_max = 1.5;
	return (range);
}

t_range	julia_scale(void)
{
	t_range	range;

	range.x_min = -1.5;
	range.x_max = 1.5;
	range.y_min = -1.5;
	range.y_max = 1.5;
	return (range);
}

t_range	tricorn_scale(void)
{
	t_range	range;

	range.x_min = -2.0;
	range.x_max = 2.0;
	range.y_min = -2.0;
	range.y_max = 2.0;
	return (range);
}

t_range	burning_ship_scale(void)
{
	t_range	range;

	range.x_min = -2.0;
	range.x_max = 1.5;
	range.y_min = -1.8;
	range.y_max = 1.8;
	return (range);
}
