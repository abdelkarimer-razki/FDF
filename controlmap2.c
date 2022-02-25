/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlmap2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:41:27 by aer-razk          #+#    #+#             */
/*   Updated: 2022/02/25 15:41:28 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	zoomin(mlxk *params)
{
	mlx_destroy_image(params->mlx, params->img);
	mlx_clear_window(params->mlx, params->mlx_win);
	params->mapz = params->mapz + 10;
	drawmap(*params, params->c, params);
}

void	zoomout(mlxk *params)
{
	if (params->mapz - 10 > 0)
	{
		mlx_destroy_image(params->mlx, params->img);
		mlx_clear_window(params->mlx, params->mlx_win);
		params->mapz = params->mapz - 10;
		drawmap(*params, params->c, params);
	}
	else
		mlx_string_put(params->mlx, params->mlx_win,
			840, 50, 16711680, "You can't zoom out anymore.");
}