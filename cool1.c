/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 17:07:24 by mlanglet          #+#    #+#             */
/*   Updated: 2013/12/06 17:42:34 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <mlx.h>

int main()
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		color;
	int		a = 0;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 420, 420, "42");
	y = 100;
	while (y < 340)
	{
		color = 0xFF0000 + a;
		a += 0x000001;
		x = 100;
		while (x < 340)
		{
			mlx_pixel_put(mlx, win, x, y, color);
			color += 0x000100;
			x++;
		}
		y++;
	}
	sleep(20);
	return (0);
}
