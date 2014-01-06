/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_lists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 14:21:15 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/22 22:46:02 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>
#include "fdf.h"

void	addnode(t_list **s, char **name)
{
	if (*s == NULL)
	{
		*s = (t_list *)malloc(sizeof(t_list));
		(*s)->content = name;
		(*s)->next = NULL ;
	}
	else
		addnode(&((*s)->next), name);
}

t_list	*duplicate_struct(t_list *ptr)
{
	t_list	*test;

	test = (t_list *)malloc(sizeof(t_list));
	if (test && ptr)
		*test = *ptr;
	return (ptr);
}

t_coord	*duplicate_list(t_coord *ptr)
{
	t_coord	*test;

	test = (t_coord *)malloc(sizeof(t_coord));
	if (test && ptr)
		*test = *ptr;
	return (ptr);
}
