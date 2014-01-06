/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 15:29:20 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/24 09:58:39 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>
#include "fdf.h"

int	expose_hook(t_env *e)
{
	start_drawing(e->img, e->ptr, e->i);
	e->i = mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_env	e;

	e.fd = open(av[1], O_RDONLY);
	if (e.fd < 0)
		return (1);
	while (get_next_line(e.fd, &e.data) >= 1 && ac > 1)
	{
		e.value = ft_strsplit(e.data, ' ');
		addnode(&e.lst, e.value);
	}
	if (ft_strcmp(e.data, "") == 0 && (!e.value || e.value[0] == '\0'))
		return (0);
	initialize_mlx(&e.mlx, &e.img);
	compute_coord(&e);
	initialize_win(&e.win, e.mlx, e.img);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_hook(e.win, 2, (1L << 0), key_hook, &e);
	mlx_do_key_autorepeaton(e.mlx);
	mlx_loop(e.mlx);
	close(e.fd);
	return (0);
}
