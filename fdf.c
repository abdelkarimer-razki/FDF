/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:40:23 by aer-razk          #+#    #+#             */
/*   Updated: 2022/01/06 14:40:25 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include "fdf.h"

void	sendingdata(t_mlxk window, int i, int j, int **c)
{
	if (j + 1 < window.x)
		repeatit(window, c[i][j] * 2, c[i][j + 1] * 2,
			window.color[i][j]);
	if (i + 1 < window.l)
		repeatitj(window, c[i][j] * 2, c[i + 1][j] * 2,
			window.color[i][j]);
}

void	drawmap(t_mlxk window, int **c, t_mlxk *windowim)
{
	int		i;
	int		j;
	int		d;

	i = -1;
	d = window.beginx;
	fdfinfo(window);
	windowim->img = mlx_new_image(window.mlx, 1920, 1080);
	window.addr = mlx_get_data_addr(windowim->img, &window.bits_per_pixel,
			&window.line_length, &window.endian);
	while (++i < window.l)
	{
		j = -1;
		window.beginx = d;
		while (++j < window.x)
		{
			sendingdata(window, i, j, c);
			window.beginx += window.mapz;
		}
		window.beginy += window.mapz;
	}
	mlx_put_image_to_window(window.mlx, window.mlx_win, windowim->img, 0, 70);
}

void	changetaille(t_mlxk *widnow, int add)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < widnow -> l)
	{
		j = 0;
		while (j < widnow -> x)
		{
			if (widnow -> c[i][j] != 0)
			{
				if (widnow -> c[i][j] + add == 0)
					widnow -> c[i][j] += add + 1;
				else
					widnow -> c[i][j] += add;
			}
			j++;
		}
		i++;
	}
}

void	secondfdf(char **arv, t_mlxk window, int arc)
{
	if (arc == 4)
	{
		window.mlx = mlx_init();
		window.mlx_win = mlx_new_window(window.mlx, 1920, 1080, "FDF");
		window.l = countlines(arv[1]);
		window.c = twodimensions(arv[1], &window);
		if (test_arg(arv[2]) || test_arg(arv[3]))
		{
			write(2, "Parameter error", 15);
			exit(0);
		}
		window.mapz = ft_atoi(arv[2]);
		window.beginy = 50;
		window.beginx = 50;
		window.mlx = mlx_init();
		window.mlx_win = mlx_new_window(window.mlx, 1920, 1080, "FDF");
		changetaille(&window, ft_atoi(arv[3]));
		drawmap(window, window.c, &window);
		mlx_hook(window.mlx_win, 2, 0, controlmap, &window);
		mlx_hook(window.mlx_win, 17, 0, ft_exit, &window);
		mlx_loop(window.mlx);
		exit(0);
	}
	else
		write(2, "Parameter error", 15);
}

int	main(int arc, char **arv)
{
	t_mlxk	window;

	window.mlx = mlx_init();
	if (arc == 2)
	{
		window.mlx = mlx_init();
		window.mlx_win = mlx_new_window(window.mlx, 1920, 1080, "FDF");
		window.l = countlines(arv[1]);
		window.c = twodimensions(arv[1], &window);
		window.mapz = 1;
		window.beginy = 50;
		window.beginx = 50;
		changetaille(&window, 0);
		drawmap(window, window.c, &window);
		mlx_hook(window.mlx_win, 2, 0, controlmap, &window);
		mlx_hook(window.mlx_win, 17, 0, ft_exit, &window);
		mlx_loop(window.mlx);
		exit(0);
	}
	else
		secondfdf(arv, window, arc);
	exit(0);
}
