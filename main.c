/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 13:30:06 by mlanglet          #+#    #+#             */
/*   Updated: 2013/12/31 20:43:52 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <libft.h>
#include "get_next_line.h"

typedef struct		s_env
{
	void	*mlx;
	void	*win;
}					t_env;

typedef struct		l_list
{
	int		x;
	int		y;
	int		next;
}					c_list;
/*
static void		draw(void *mlx, void *win)
{
	int		x;
	int		y;

	y = 100;
	while (y < 200)
	{
		x = 100;
		while (x < 200)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}
*/
static int     mouse_hook(int button, int x, int y, t_env *e)
{
	(void)e;
	printf("mouse: %d (%d:%d)\n", button, x, y);
	return (0);
}

static int		key_hook(int keycode, t_env *e)
{
	(void)e;
	printf("key: %d\n", keycode);
	if (keycode == 65307)
		exit(0);
	return (0);
}
/*
static int		expose_hook(t_env *e)
{
	draw(e->mlx, e->win);
	return (0);
}
*/
/*
static int		ft_draw_line(t_env *e, c_list emp1, c_list emp2)
{
	int		x;

	x = emp1.x;
	while (x <= emp2.x)
	{
		mlx_pixel_put(e->mlx, e->win, x, emp1.y + ((emp2.y - emp1.y) * (x - emp1.x)) / (emp2.x - emp1.x), 0xFFFFFF);
		x++;
	}
	return (0);
}
*/
/*
static int      ft_draw_line2(t_env *e, c_list emp1, c_list emp2)
{
	int     y;

	y = emp1.y;
	while (y <= emp2.y)
	{
		mlx_pixel_put(e->mlx, e->win, emp1.x + ((emp2.x - emp1.x) * (y - emp1.y)) / (emp2.y - emp1.y), y, 0xFFFFFF);
		y++;
	}
	return (0);
}
*/
static size_t	ft_count(char *s)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ')
			c++;
		i++;
	}
	return (c);
}

static c_list	**ft_init(char *file)
{
	int		i;
	size_t		j;
	int		a = 0;
	int		b = 0;
	int		fd;
	char	*line;
	int		*l;
	int		z;
	size_t		c;
	c_list	**coord;

	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) != 0)
		i++;
	coord = (c_list **)malloc(sizeof(*coord) * (i + 1));
	close(fd);
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) != 0)
	{
		j = 0;
		a = 0;
		z = 0;
		c = ft_count(line);
		l = ft_memalloc(c + 1);
		while (line[j] != '\0')
		{
			if (line[j] != ' ')
			{
				l[z] = ft_atoi(&line[j]);
//				printf("%d ", l[z]);
				z++;
			}
			j++;
		}
		j = 0;
		coord[i] = (c_list *)malloc(sizeof(**coord) * (c + 1));
		while (j < c)
		{
			printf("%d ", l[j]);
			coord[i][j].x = 400 + 8 * (i - j);
			coord[i][j].y = 200 + 8 * (((l[j])) + ((0.5 * i) + (0.5 * j)));

//			coord[i][j].x = 200 + 4 * ((a) - (1 * b));
//			coord[i][j].y = 200 + 4 * (((l[j])) + ((0.5 * a) + (0.5 * b)));
			coord[i][j].next = 1;
			j++;
			a += 2;
		}
		printf("\n");
		coord[i][j].next = 0;
		b += 3;
		i++;
	}
	coord[i] = '\0';
	close(fd);
	return (coord);
}

int		main(int argc, char **argv)
{
	t_env	e;
	c_list	**coord;
	int		fd;
//	char	*line;
	int		i;
	int		j;
	int		a;
//	int		b;

	j = 0;
	a = 0;
	if (argc == 2)
	{
		coord = ft_init(argv[1]);
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, 800, 600, "42");
		mlx_mouse_hook(e.win, mouse_hook, &e);
		mlx_key_hook(e.win, key_hook, &e);
//		mlx_expose_hook(e.win, expose_hook, &e);
		fd = open(argv[1], O_RDONLY);
/*		i = 0;
		while (coord[i + 1] != '\0')
		{
			j = 0;
			while (coord[i][j + 1].next != 0)
			{
				ft_draw_line(&e, coord[i][j], coord[i + 1][j]);
				ft_draw_line2(&e, coord[i][j], coord[i][j + 1]);
				j++;
			}
			i++;
		}
*/
		i = 0;
		while (coord[i] != '\0')
		{
			j = 0;
			while (coord[i][j].next != 0)
			{
				mlx_pixel_put(e.mlx, e.win, coord[i][j].x, coord[i][j].y, 0xFFFFFF);
				j++;
			}
			i++;
		}
/*	
		while (get_next_line(fd, &line) != 0)
		{
			i = 0;
			b = 0;
			while (line[i] != '\0')
			{
				if (line[i] != ' ')
				{
					if (ft_atoi(&line[i]) > 0)
						mlx_pixel_put(e.mlx, e.win, coord[a][b].x, coord[a][b].y, 0xFF0000);
					else
						mlx_pixel_put(e.mlx, e.win, coord[a][b].x, coord[a][b].y, 0xFFFFFF);
				}
				b++;
				i++;
			}
			j += 3;
			a++;
		}*/
		mlx_loop(e.mlx);
	}
	return (0);
}
