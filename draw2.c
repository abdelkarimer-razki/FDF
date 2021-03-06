/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:47:04 by aer-razk          #+#    #+#             */
/*   Updated: 2022/02/23 15:47:06 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <math.h>
#include <stdio.h>

double	x2(t_mlxk window, int osize)
{
	return ((window.beginy - window.mapz) / 3 + window.beginx
		+ window.mapz + osize);
}

double	y2(t_mlxk window, int osize)
{
	return (0.1 * window.beginx + window.beginy - osize);
}

double	ft_tan(double x0, double y0, t_mlxk window, int osize)
{
	return ((y2(window, osize) - y0) / (x2(window, osize) - x0));
}

void	repeatit(t_mlxk window, int size, int osize, int color)
{
	double	x0;
	double	y0;
	double	m;
	int	y21 = y2(window, osize);
	int x21 = x2(window, osize);

	y0 = 0.1 * (window.beginx - window.mapz) + window.beginy - size;
	x0 = (window.beginy - window.mapz) / 3 + window.beginx + size;
	m = ft_tan(x0, y0, window, osize);
	if ((m < 1 && m > 0) || (m < 0 && m > -1))
	{
		while ((int)x0 != x21)
		{
			my_mlx_pixel_put(&window, x0, y0, color);
			x0++;
			y0 = y0 + m;
		}
	}
	else
	{
		while ((int)y0 != y21)
		{
			my_mlx_pixel_put(&window, x0, y0, color);
			y0++;
			x0 = x0 + 1 / m;
		}
	}
}
