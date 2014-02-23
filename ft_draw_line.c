/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 16:12:24 by mlanglet          #+#    #+#             */
/*   Updated: 2013/12/21 17:10:01 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int		ft_draw_1(t_env *e, c_list emp1, c_list emp2)
{
	int		x;

	x = emp1.x;
	while (x <= emp2.x)
	{
		mlx_pixel_put(e->mlx, e->win, x,
				emp1.y + ((emp2.y - emp1.y) * (x - emp1.x))
				/ (emp2.x - emp1.x), 0xFFFFFF);
		x++;
	}
	return (0);
}

static int		ft_draw_2(t_env *e, c_list emp1, c_list emp2)
{
	int		y;

	y = emp1.y;
	while (y <= emp2.y)
	{
		mlx_pixel_put(e->mlx, e->win,
				emp1.x + ((emp2.x - emp1.x) * (y - emp1.y))
				/ (emp2.y - emp1.y), y, 0xFFFFFF);
		y++;
	}
	return (0);
}

void	ft_draw_line(t_env *e, c_list **coord)
{
	int		i;
	int		j;

	i = 0;
	while (coord[i + 1] != '\0')
	{
		j = 0;
		while (coord[i][j + 2].next != 0)
		{
			if (coord[i][j].x < coord[i][j + 1].x)
				ft_draw_1(e, coord[i + 1][j], coord[i][j]);
			if (coord[i][j].x > coord[i][j + 1].x)
				ft_draw_1(e, coord[i][j], coord[i + 1][j]);
			if (coord[i][j].y < coord[i][j + 1].y)
				ft_draw_2(e, coord[i][j], coord[i][j + 1]);
			if (coord[i][j].y > coord[i][j + 1].y)
				ft_draw_2(e, coord[i][j + 1], coord[i][j]);
			ft_draw_2(e, coord[i + 1][j], coord[i + 1][j + 1]);
			j++;
			ft_draw_1(e, coord[i + 1][j], coord[i][j]);
		}
		i++;
	}
}
