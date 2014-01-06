/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 14:37:02 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/22 23:27:50 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>
#include "fdf.h"

static void	treatcase(int keycode, t_env **e)
{
		if (keycode == 65362)
			(*e)->z_move = (*e)->z_move + 1;
		if (keycode == 65364)
			(*e)->z_move = (*e)->z_move - 1;
		if (keycode == 97)
			(*e)->x_move = (*e)->x_move - 10;
		if (keycode == 100)
			(*e)->x_move = (*e)->x_move + 10;
		if (keycode == 119)
			(*e)->y_move = (*e)->y_move - 10;
		if (keycode == 115)
			(*e)->y_move = (*e)->y_move + 10;
		if (keycode == 65363)
			(*e)->rot = (*e)->rot + 1;
		if (keycode == 65361)
			(*e)->rot = (*e)->rot - 1;
}

int			key_hook(int keycode, t_env *e)
{
	t_coord	*new;

	new = NULL;
	(void)e;
	if (keycode == 65307)
		exit (0);
	if (keycode == 65362 || keycode == 65364 || keycode == 97 \
			|| keycode == 100 || keycode == 119 || keycode == 115 \
			|| keycode == 65363 || keycode == 65361)
	{
		treatcase(keycode, &e);
		new = compute_coord_plus(*e);
		e->img = mlx_new_image(e->mlx, IMG_X, IMG_Y);
		start_drawing(e->img, new, e->ptr->j);
		e->openwin = mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	}
	return (0);
}
