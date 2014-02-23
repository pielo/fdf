/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 12:38:51 by mlanglet          #+#    #+#             */
/*   Updated: 2013/12/21 16:21:24 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>

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

void		ft_draw_line(t_env *e, c_list **coord);
c_list		**ft_init(char *file);

#endif
