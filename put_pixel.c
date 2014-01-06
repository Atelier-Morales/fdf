/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 15:17:57 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/22 22:29:39 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>
#include "fdf.h"

void	mlx_pixel_put_to_image(void *img, int x, int y, unsigned long color)
{
	t_img	pic;
	int		i;

	pic.data = mlx_get_data_addr(img, &pic.bpp, &pic.sizeline, &pic.endian);
	i = x * 4 + y * pic.sizeline;
	if (x >= 0 && y >= 0 && x <= WIN_X && y <= WIN_Y)
	{
		pic.data[i] = color % 256;
		color /= 256;
		pic.data[i + 1] = color % 256;
		color /= 256;
		pic.data[i + 2] = color % 256;
		color /= 256;
		pic.data[i + 3] = 0;
		color /= 256;
	}
}
