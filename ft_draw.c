/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 14:14:06 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/22 23:26:11 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>
#include "fdf.h"

static void	pixel_y_put(void *img, t_coord *ptr, t_coord *test)
{
	mlx_pixel_put_to_image(img, ptr->x + (ptr->y_i - ptr->y) * \
			((test->x - ptr->x) / (test->y - ptr->y)), ptr->y_i, \
			((COLOR) - ptr->z));
}

static void	pixel_x_put(void *img, t_coord *ptr, double x)
{
	mlx_pixel_put_to_image(img, x, ptr->y + (x - ptr->x) * \
			((ptr->next->y - ptr->y) / (ptr->next->x - ptr->x)), \
			((COLOR) - ptr->z));
}

static void	pixel_ybis_put(void *img, t_coord *ptr, double y)
{
	mlx_pixel_put_to_image(img, ptr->x + (y - ptr->y) * \
			((ptr->next->x - ptr->x) / (ptr->next->y - ptr->y)), \
			y, ((COLOR) - ptr->z));
}

void		draw_columns(void *img, t_coord *ptr, int i)
{
	t_coord	*test;

	test = duplicate_list(ptr);
	while (ptr->j < i)
	{
		test = test->next;
		ptr->j++;
	}
	while (test != NULL)
	{
		ptr->y_i = ptr->y;
		while (ptr->y_i <= test->y && (ptr->x - test->x) <= X_SIZ + 30)
		{
			pixel_y_put(img, ptr, test);
			ptr->y_i = (ptr->y_i + 0.01);
		}
		while (ptr->y_i >= test->y && (ptr->x - test->x) <= X_SIZ + 30)
		{
			pixel_y_put(img, ptr, test);
			ptr->y_i = (ptr->y_i - 0.01);
		}
		test = test->next;
		ptr = ptr->next;
	}
}

void		draw_lines(void *img, t_coord *ptr, int i)
{
	double  	x;
	double		y;
	int			j;

	j = 0;
	while (ptr->next != NULL)
	{
		if (j == i)
			j = 0;
		x = ptr->x;
		y = ptr->y;
		while (x <= ptr->next->x)
		{
			pixel_x_put(img, ptr, x);
			x = (x + 0.01);
		}
		while (y >= ptr->next->y && j < (i - 1))
		{
			pixel_ybis_put(img, ptr, y);
			y = (y - 0.01);
		}
		j++;
		ptr = ptr->next;
	}
}
