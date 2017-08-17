/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 22:51:58 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/08/08 22:52:01 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_num_atoi(char **line, int *num)
{
	int		count;
	int		minus;

	*num = 0;
	minus = (**line == '-') ? -1 : 1;
	*line += (**line == '-') ? 1 : 0;
	while (**line == '0')
		(*line)++;
	count = 0;
	while (count <= 10 && ft_isdigit((*line)[count]))
		count++;
	if (count > 10)
		return (0);
	if (count == 10 && ft_strncmp(*line, "2147483647", 10) > 0 &&
		(!minus || ft_strncmp(*line, "2147483648", 10) != 0))
		return (0);
	while (count > 0)
	{
		*num = (*num * 10) + minus * (**line - '0');
		count--;
		(*line)++;
	}
	return (1);
}

t_room	*presence_room(t_room *curr, char *name, size_t len_name)
{
	while (curr != NULL && !ft_strnequ(curr->name, name, len_name))
		curr = curr->next;
	return (curr);
}

void	delete_links(t_link **first)
{
	t_link	*prev;

	while (*first)
	{
		prev = *first;
		*first = (*first)->next;
		free(prev);
	}
}

void	delete_list_rooms(t_room **first)
{
	t_room	*prev;

	while (*first)
	{
		prev = *first;
		*first = (*first)->next;
		ft_strdel(&prev->name);
		free(prev);
	}
}

void	delete_all_data(t_room **first, t_way **all_ways)
{
	t_room	*tmp;
	t_way	*prev;

	tmp = *first;
	while (tmp)
	{
		delete_links(&tmp->links);
		tmp = tmp->next;
	}
	delete_list_rooms(first);
	while (*all_ways)
	{
		prev = *all_ways;
		*all_ways = (*all_ways)->next;
		free(prev->rooms);
		free(prev);
	}
}
