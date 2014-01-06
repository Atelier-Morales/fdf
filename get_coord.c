/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 14:28:19 by fmorales          #+#    #+#             */
/*   Updated: 2014/01/04 17:28:48 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>
#include "fdf.h"

void		stock_xy(t_coord **ptr, t_env *e, int z)
{
	t_matrix	*a;
	double      y;
	double      x;

	a = (t_matrix *)malloc(sizeof(t_matrix));
	a->x1 = (X_POS + e->x_move) + (e->i * 30) - (e->j * 30) - (z / 2);
	a->y1 = (Y_POS + e->y_move) + (e->i * 20) + (e->j * 20) - (z * 2);
	a->x2 = (X_POS + X_SIZ + e->x_move) + (e->i * 30) - (e->j * 3) - (z / 2);
	a->y2 = (Y_POS + Y_SIZ + e->y_move) + (e->i * 20) + (e->j * ) - (z * 2);
	x = a->x1;
	y = a->y1 + (x - a->x1) * ((a->y2 - a->y1) / (a->x2 - a->x1));
	if (*ptr == NULL)
	{
		*ptr = (t_coord *)malloc(sizeof(t_coord));
		(*ptr)->x = x;
		(*ptr)->y = y;
		(*ptr)->z = z;
		(*ptr)->next = NULL;
		free(a);
	}
	else
		stock_xy(&((*ptr)->next), e, z);
}

t_coord		*compute_coord_plus(t_env e)
{
	t_coord	*new;

	e.j = 0;
	new = NULL;
	while (e.lst != NULL)
	{
		e.i = 0;
		while (e.lst->content[e.i] != '\0')
		{
			if (ft_atoi(e.lst->content[e.i]) != 0)
				stock_xy(&new, &e, (e.z_move + ft_atoi(e.lst->content[e.i])));
			else
				stock_xy(&new, &e, ft_atoi(e.lst->content[e.i]));
			e.i++;
		}
		e.j++;
		e.lst = e.lst->next;
	}
	return (new);
}

void		compute_coord(t_env *e)
{
	t_list	*test;

	test = duplicate_struct(e->lst);
	while (test != NULL)
	{
		e->i = 0;
		while (test->content[e->i] != '\0')
		{
			stock_xy(&e->ptr, e, ft_atoi(test->content[e->i]));
			e->i++;
		}
		e->j++;
		test = test->next;
	}
}
