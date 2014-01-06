/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 16:50:26 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/22 22:25:35 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>
#include "fdf.h"

void	initialize_mlx(void **mlx, void **img)
{
	*mlx = mlx_init();
	*img = mlx_new_image(*mlx, IMG_X, IMG_Y);
}

void	start_drawing(void *img, t_coord *ptr, int i)
{
	draw_lines(img, ptr, i);
	draw_columns(img, ptr, i);
}

void	initialize_win(void **win, void *mlx, void *img)
{
	int	i;

	*win = mlx_new_window(mlx, WIN_X, WIN_Y, "42");
	i = mlx_put_image_to_window(mlx, *win, img, 0, 0);
}
