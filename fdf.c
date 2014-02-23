/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 11:57:41 by mlanglet          #+#    #+#             */
/*   Updated: 2013/12/21 18:06:37 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fdf.h>

static int		key_hook(int keycode, t_env *e)
{
	(void)e;
	if (keycode == 65307)
		exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	e;
	c_list	**coord;

	if (argc == 2)
	{
		e.mlx = mlx_init();
		if (!e.mlx)
			return (1);
		e.win = mlx_new_window(e.mlx, 1280, 768, "42");
		mlx_key_hook(e.win, key_hook, &e);
		coord = ft_init(argv[1]);
		ft_draw_line(&e, coord);
		mlx_loop(e.mlx);
	}
	else
		ft_putstr("Mettre un nom de fichier\n");
	return (0);
}
