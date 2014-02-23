/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 12:47:00 by mlanglet          #+#    #+#             */
/*   Updated: 2013/12/23 18:00:29 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>
#include "get_next_line.h"
#include <fdf.h>

static int		*ft_lin(char *line, size_t *max)
{
	char		**stock;
	int			*rev;
	size_t		i;

	i = 0;
	stock = ft_strsplit(line, ' ');
	while (stock[i] != '\0')
		i++;
	*max = i;
	rev = ft_memalloc(i);
	i = 0;
	while (stock[i] != '\0')
	{
		rev[i] = ft_atoi(stock[i]);
		i++;
	}
	return (rev);
}

static c_list		**ft_create(c_list **coord, int fd, int size)
{
	size_t		i;
	size_t		j;
	size_t		max;
	char		*line;
	int			*new;

	coord = (c_list **)malloc(sizeof(*coord) * (size + 1));
	i = 0;
	while (get_next_line(fd, &line) != 0)
	{
		j = 0;
		new = ft_lin(line, &max);
		coord[i] = (c_list *)malloc(sizeof(**coord) * (max + 1));
		while (j <= max)
		{
			coord[i][j].x = 300 + -16 * (i - j);
			coord[i][j].y = 100 + -16 * (0.14 * new[j] - 0.9 * i - 0.9 * j);
			coord[i][j].next = 1;
			j++;
		}
		coord[i][j].next = 0;
		i++;
	}
	coord[i] = '\0';
	return (coord);
}

c_list			**ft_init(char *file)
{
	int			i;
	int			fd;
	char		*line;
	c_list		**coord;

	i = 0;
	coord = NULL;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	i++;
	close(fd);
	fd = open(file, O_RDONLY);
	coord = ft_create(coord, fd, i);
	close(fd);
	return (coord);
}
