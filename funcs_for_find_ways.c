/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_for_find_ways.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 22:42:12 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/08/08 22:42:15 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_mark_link(t_room *name1, t_room *name2)
{
	t_link	*tmp;

	tmp = name1->links;
	while (tmp)
	{
		if (tmp->room == name2)
		{
			tmp->mark = 1;
			return ;
		}
		tmp = tmp->next;
	}
}

void	set_mark_on_way(t_room **way)
{
	int		i;

	i = 0;
	while (i < way[0]->dist)
	{
		set_mark_link(way[i], way[i + 1]);
		set_mark_link(way[i + 1], way[i]);
		i++;
	}
}

void	clear_all_distances(t_room *first)
{
	while (first)
	{
		first->dist = 2147483647;
		first = first->next;
	}
}

t_way	*new_way(int length)
{
	t_way	*tmp;

	tmp = (t_way *)malloc(sizeof(t_way));
	if (tmp)
	{
		tmp->len = length;
		tmp->rooms = NULL;
		tmp->next = NULL;
	}
	return (tmp);
}

void	add_way_back(t_way **first, t_way *new)
{
	t_way	*tmp;

	if (*first)
	{
		tmp = *first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*first = new;
}
