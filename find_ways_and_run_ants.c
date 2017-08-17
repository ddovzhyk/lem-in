/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ways_and_run_ants.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 22:28:20 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/08/08 22:28:21 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		dfs_visit(t_room *prev, t_room *curr, t_room *end)
{
	t_link	*tmp_link;
	int		res;

	res = 0;
	if (prev && prev->dist + 1 < curr->dist)
	{
		curr->dist = prev->dist + 1;
		curr->prev = prev;
	}
	else if (prev)
		return (0);
	if (curr == end)
		return (1);
	tmp_link = curr->links;
	while (tmp_link)
	{
		if (tmp_link->mark == 0)
			if (dfs_visit(curr, tmp_link->room, end) && res == 0)
				res = 1;
		tmp_link = tmp_link->next;
	}
	return (res);
}

t_room	**get_min_way(t_room *end)
{
	int		i;
	t_room	*curr;
	t_room	**way;

	way = (t_room **)malloc(sizeof(t_room *) * (end->dist + 1));
	i = 0;
	curr = end;
	while (curr)
	{
		way[i] = curr;
		curr = curr->prev;
		i++;
	}
	return (way);
}

int		find_ways(t_way **all_way, t_room *first, t_room *start, t_room *end)
{
	t_way	*tmp;

	start->dist = 0;
	while (dfs_visit(NULL, start, end))
	{
		tmp = new_way(end->dist);
		tmp->rooms = get_min_way(end);
		set_mark_on_way(tmp->rooms);
		clear_all_distances(first);
		start->dist = 0;
		add_way_back(all_way, tmp);
	}
	return (*all_way ? 1 : 0);
}

int		shift_ants(t_way way, int *flag_for_print)
{
	int	i;

	i = 0;
	while (i < way.len - 1)
	{
		if (way.rooms[i + 1]->ant != 0)
		{
			*flag_for_print = (*flag_for_print == 1) ? ft_printf(" ") : 1;
			ft_printf("L%d-%s", way.rooms[i + 1]->ant, way.rooms[i]->name);
			if (i == 0)
				way.rooms[i]->ant++;
			else
				way.rooms[i]->ant = way.rooms[i + 1]->ant;
			way.rooms[i + 1]->ant = 0;
		}
		i++;
	}
	return (1);
}

void	run_ants(t_way *all, t_room *start, t_room *end, int index_ant)
{
	t_room	*sec_room;
	t_way	*tmp;
	int		print_flag;

	while (start->ant > end->ant && (tmp = all))
	{
		print_flag = 0;
		while (tmp && index_ant && shift_ants(*tmp, &print_flag))
			tmp = tmp->next;
		tmp = all;
		while (tmp && index_ant < start->ant)
		{
			sec_room = tmp->rooms[tmp->len - 1];
			if (tmp == all || start->ant - index_ant > tmp->len - all->len)
				while (sec_room->ant == 0 ||
						(index_ant < start->ant && sec_room == end))
				{
					sec_room->ant = ++index_ant;
					print_flag = (print_flag == 1) ? ft_printf(" ") : 1;
					ft_printf("L%d-%s", index_ant, sec_room->name);
				}
			tmp = tmp->next;
		}
		ft_printf("\n");
	}
}
